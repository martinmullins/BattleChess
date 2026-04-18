/*
 * standalone_main.h — Replaces LLVMFuzzerTestOneInput with a main() that
 * exercises the harness against the seed corpus files in seeds/<target>/.
 *
 * Included via -include when building with STANDALONE_TEST.
 */
#ifdef STANDALONE_TEST

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

/* Forward declaration of the real harness function. */
int LLVMFuzzerTestOneInput(const unsigned char *data, size_t size);

static void run_file(const char *path)
{
    FILE *f = fopen(path, "rb");
    if (!f) { perror(path); return; }
    struct stat st;
    stat(path, &st);
    if (st.st_size == 0) { fclose(f); return; }
    unsigned char *buf = malloc((size_t)st.st_size);
    size_t n = fread(buf, 1, (size_t)st.st_size, f);
    fclose(f);
    LLVMFuzzerTestOneInput(buf, n);
    free(buf);
}

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "usage: %s <seed_dir>...\n", argv[0]);
        /* Run with empty input as smoke test. */
        unsigned char empty[64] = {0};
        for (size_t sz = 0; sz <= 64; sz += 4)
            LLVMFuzzerTestOneInput(empty, sz);
        return 0;
    }
    for (int i = 1; i < argc; i++) {
        DIR *dir = opendir(argv[i]);
        if (!dir) { run_file(argv[i]); continue; }
        struct dirent *ent;
        char path[4096];
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] == '.') continue;
            snprintf(path, sizeof(path), "%s/%s", argv[i], ent->d_name);
            run_file(path);
        }
        closedir(dir);
    }
    return 0;
}

#endif /* STANDALONE_TEST */

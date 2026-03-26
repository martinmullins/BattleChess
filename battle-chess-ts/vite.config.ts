import { defineConfig } from 'vite';

export default defineConfig({
  base: './',
  build: {
    outDir: '../public',
    emptyOutDir: true,
    target: 'es2020',
  },
  test: {
    environment: 'node',
    include: ['src/**/*.test.ts'],
  },
});

import { defineShikiSetup } from '@slidev/types';

export default defineShikiSetup(async ({ loadTheme }) => {
  return {
    theme: {
      dark: await loadTheme(require.resolve('./monokai.json')),
      light: await loadTheme(require.resolve('./monokai.json')),
    },
  };
});

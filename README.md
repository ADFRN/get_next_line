# get_next_line

![Result](./result.png)

Implémentation de `get_next_line(int fd)`, une fonction qui lit et retourne la prochaine ligne (terminée par `\n` si présent) depuis un descripteur de fichier.

## `char *get_next_line(int fd);`
  - Retourne la prochaine ligne lue depuis `fd` (inclut `\n` si présent).
  - Retourne `NULL` en cas de fin de fichier ou d'erreur.
  - La chaîne retournée doit être libérée par l’appelant avec `free`.

## Fichiers
- `get_next_line.c` — logique principale (lecture, extraction et gestion du stash)
- `get_next_line_utils.c` — utilitaires (duplication, concaténation, longueur, détection de `\n`)
- `get_next_line.h` — prototypes, includes, et définition de `BUFFER_SIZE`


## Règles et contraintes 42
- Respect de la Norminette (tabulations, taille des fonctions, en-têtes, etc.)
- Pas d’allocation sauvage non libérée (leaks)
- `get_next_line` doit fonctionner pour tous les `fd` valides, et retourner `NULL` proprement en cas d’erreur ou de fin de fichier.

## Notes de maintenance
- `BUFFER_SIZE` influe sur la fréquence de lecture (`read`). Adapter selon les besoins et les tests.
- Sur erreur `read(fd, ...) == -1`, la mémoire statique utilisée doit être "nettoyée" pour éviter d’empiler des états incohérents.
- Les utilitaires gèrent les pointeurs `NULL` pour éviter les segfaults (ex: `ft_strjoin`, `ft_strlen`).

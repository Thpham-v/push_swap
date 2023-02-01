# push_swap
push_swap - Trier une liste d'entiers en utilisant un ensemble limité d'opérations
Ce projet consiste à écrire deux programmes en C : push_swap et checker. Le programme push_swap prend en entrée une liste d'entiers et retourne une séquence d'opérations pour trier cette liste, tandis que le programme checker vérifie si la séquence d'opérations retournée par push_swap trie effectivement la liste.

# Fonctionnalités
Tri d'une liste d'entiers à l'aide d'un ensemble limité d'opérations.
Vérification de la validité de la séquence d'opérations retournée par push_swap.
# Compilation
Pour compiler les deux programmes, utilisez la commande make dans le répertoire racine. Cela générera les exécutables push_swap et checker.

# Exécution
push_swap
Pour exécuter push_swap, utilisez la commande ./push_swap [liste_d'entiers] où [liste_d'entiers] est la liste d'entiers à trier.

# checker
Pour exécuter checker, utilisez la commande ./checker [liste_d'entiers] suivie de la séquence d'opérations retournée par push_swap. Par exemple, ./checker [liste_d'entiers] $(./push_swap [liste_d'entiers]).

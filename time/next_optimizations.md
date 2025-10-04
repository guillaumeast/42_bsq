Stocker out_len dans solution

Ne pas initialiser les valeurs dans solution.table et solution.output

Directement modifier map plutôt que de regénérer output ? (permet de ne pas modifier les caractères en dehors de boundaries_box)

print.c => custom strncat (remove n, strlen only once)

dynamic reading buffer (check each buffer validity in case of stdin random flooding)
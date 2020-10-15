# Drawing

Les fonctionnalités :
- `init_drawing(largeur,hauteur,delai_anim)` : Permet de créer une zone (un "motif") de dessin d'une largeur `largeur` et d'une hauteur `hauteur`. `delai_anim`est le temps que prendra chaque ligne à se dessiner (en seconde). Ce délai peut-être décimal, par exemple 0.5 pour 1/2 seconde. Le point de début de traçage est positioné au centre de la zone.
- `draw(longeur)` : Permet de tracer une ligne de taille `longueur` (en pixels) dans le motif.
- `move(longeur)` : Permet de se déplacer d'une taille `longueur` (en pixels) dans le motif sans tracer de ligne.
- `turn(angle, direction)` : Permet de modifier la direction de traçage (par défaut l'angle est de 0° vers la droite). On lui indique l'angle de rotation en degrés et la direction gauche ou droite grâce à l'une des constantes de direction `LEFT` ou `RIGHT`.
- `change_color(rouge,vert,bleu)` : Permet de définir la couleur de traçage en fixant l'intensité des composantes rouge, verte et bleue. 
- `display_drawing()` : Affiche le motif réalisé.

# Demo Drawing

@[Sample paper]({"stubs": ["main.c"],"command": "sh /project/target/run.sh", "project" : "sample"})


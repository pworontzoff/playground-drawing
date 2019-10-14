# Drawing

Les fonctionnalités :
- `init_drawing(largeur,hauteur)` : Permet de créer une zone de dessin d'une largeur `largeur` et d'une hauteur `hauteur`. Le point de début de traçage est positioné au centre de la zone.
- `draw(longeur)` : Permet de tracer une ligne de taille `longueur` (en pixels) dans le motif.
- `turn(angle, direction)` : Permet modifie la direction de traçage (par défaut l'angle est de 0° vers la droite). On lui indique l'angle de rotation et la direction gauche ou droite grâce à l'une des constantes de direction `LEFT` ou `RIGHT`.
- `change_color(rouge,vert,bleu)` : Permet de définir la couleur de traçage en fixant l'intensité des composantes rouge, verte et bleu. 
- `display_drawing()` : Affiche le motif réalisé.

**Remarque :** Le principe de traçage est d'utiliser un trait continu. On ne sait jamais interrompre le tracé ou se déplacer par bon vers un autre point de la zone de dessin. Il est par contre possible de repasser sur un trait existant.

# Demo Drawing

@[Sample paper]({"stubs": ["main.c"],"command": "sh /project/target/run.sh", "project" : "sample"})


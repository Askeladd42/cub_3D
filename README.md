# cub3d
(ENG) My Project cub3d for 42.

WARNING !

If you are on linux OS, change this on the parse.h file :

```
# define FW 119
# define BW 115
# define L 97
# define R 100
# define LR 65361
# define RR 65363
# define RUN 65505
```

and this on the raycast.h :

```
#include "parse.h"
#include "../minilibx_linux/mlx.h"
#include <math.h>
```

(FR) Si vous êtes sur une VM Linux en AZERTY, changez cela dans les commandes du raycast.h :

```
# define FW 122
# define L 113
```

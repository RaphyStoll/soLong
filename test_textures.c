#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

 int main()
 {
     void *mlx_ptr;    // Pointeur pour MiniLibX
     void *win_ptr;    // Pointeur pour la fenêtre
     void *img_ptr;    // Pointeur pour l'image
     int img_width;    // Largeur de l'image
     int img_height;   // Hauteur de l'image

     // Initialisation de MiniLibX
     mlx_ptr = mlx_init();
     if (!mlx_ptr)
     {
         printf("Error: Failed to initialize MiniLibX\n");
         return (1);
     }

     // Création d'une fenêtre
     win_ptr = mlx_new_window(mlx_ptr, 800, 800, "Texture Test");
     if (!win_ptr)
     {
         printf("Error: Failed to create window\n");
         return (1);
     }
	img_ptr = mlx_new_image(mlx_ptr, 64, 64);
	
     // Chargement de la texture
     img_ptr = mlx_xpm_file_to_image(mlx_ptr, "/textures/floor.xpm", &img_width, &img_height);
     if (!img_ptr)
     {
         printf("Error: Failed to load texture\n");
         return (1);
     }

     // Affichage de la texture dans la fenêtre
     mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 100, 100);

     // Lancement de la boucle d'événements
     mlx_loop(mlx_ptr);

     return (0);
 }

 
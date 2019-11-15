#include "image.h"
#include <random>

image::image()
{

}

image::aleatoire()
{
   std::default_random_engine RAND_E;
   std::uniform_int_distribution<int> distrib{1,9};
   for (int i = 0; i < 30; i++)
   {
       std::cout << distrib(RAND_E) << std::endl;
   }
}

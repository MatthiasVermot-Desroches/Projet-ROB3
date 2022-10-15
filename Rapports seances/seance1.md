# Etude du LIDAR 14/10

## Conception général :
Un moteur pas à pas qui entraîne par une courroie la rotation du miroir. La tension de celle-ci est ajusté grâce à un roulement qui translate. L’axe du miroir est fixé par un roulement à bille pour éviter toute vibration. Le pivot du miroir est assuré par deux tiges qui translate en même temps par l’intermédiaire d’un servo-moteur afin d’éviter tout arc-boutement.

## Choix du moteur pas à pas :
Test d’un moteur NEMA 17 avec son driver A4988. Le pas minimum obtenu est de 1,8° et la vitesse maximal est de 60 rpm. La vitesse étant deux fois plus que celle nécessaire, on pourra faire une réduction avec la courroie pour obtenir une précision de 0,9°. 

## LIDAR-Lite v3HP :
Pas réussi à le faire fonctionner, il faudra réessayer avec un condensateur ainsi que des résistances de tirages.

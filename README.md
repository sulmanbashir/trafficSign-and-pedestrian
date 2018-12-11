                                EIP
                       Rider Companion Helmet
                       
1er sprint :
                -   detection des pietons
                
2eme sprint :
                -   détection des panneaux de danger
                
                
---------------------------------------------------------------------------------


14/01/2018 : - recherche d'image depuis le suivi du 21 décembre
             - regroupement des images négatives et positives
             - modification de la taille et des extension des images
             - lancement du training le 13/01/2018
             
21/01/2018 : - serveur du lab eip a planté, haarcascade perdu !
             - j'ai relancer un autre training sur le serveur de fabien
             - changement de stratégie pour la reconnaissance des panneaux : éviter le haartraining et utiliser les methodes FAST, SURF ou SIFT.
             - code non fonctionnel dans l'état; possibilité de le lancer
             - problème de latence avec le haarcascade réglé; rendu plus fluide !
                       
                       
28/01/2018 : - code non fonctionnel;
             - reconnaissance de tous les panneaux de formes rondes; ce bout de code ne se trouve pas dans cette branche mais une branche à part que je rajouterais une fois que j'aurai la detection des panneaux de danger en cours de reconnaissance;
             

11/02/2018 : - reconnaissances des formes rondes; dans mon cas, la reconnaissance des panneaux fonctionne grâce à un bon paramétrage du                         houghcircles;
             - recherche des vidéos pour les démos, découpage des séquences pour éviter d'avoir des vidéos trop longues
             - la reconnaissances des formes triangles est prête, je l'intégre d'ici le prochain rendu
             - pour tester mon code vous pouvez le lancer avec les videos suivantes, il ya encore quelque faux positifs mais c'est tout à fait normal :
                        + moto-vlog1.mp4
                        + demo-2.mp4
                        + moto-vlog4-1.mp4
                        + moto-vlog6-1.mp4
                        
                                     
25/02/2018 : - test :
                    + moto-vlog1.mp4
                    + demo-2.mp4
                    + moto-vlog4-1.mp4
                    + moto-vlog6-1.mp4
                    + moto-vlog7.mp4
            - reconnaissance des panneaux ronds et triangles; il détecte toutes les formes rondes et triangles, cela signifie qu'il ne s'arrete pas que aux panneaux. La raison de ce choix est que j'ai juger plus simple de faire comme sa, ensuite à l'aide des cascades je pourrais faire matchés avec les différents signification plus facilement pour chaque panneau.
            - quelques faux positifs mais devrait être corriger lors des sprint suivants;
            - a tester avec les videos que j'ai cités plus haut
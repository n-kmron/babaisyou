<h1>BABA IS YOU by Cameron (58008) & Reda (58063)</h>
<h2>Release 1</h2>
<h3>Date : 17/02/2023</h3>
<p>Les documents relatifs à la première release du projet se trouvent dans le répertoire <i>'remise_01'</i> (Fichier UML et PDF)
PS : le fichier .mdj n'est pas documenté car un fichier pdf d'explications est demandé</p>

<br>
<h2>Release 2</h2>
<h3>Date : 21/04/2023</h3>
<p>Le projet console est disponible dans le répertoire <i>'remise_02/BabaIsYou'</i>.</p>
<p>le <code>working directory</code> de ce projet doit être (à partir de la racine 'BabaIsYou'): <code>/BabaIsYou/src</code></p>
<p><b>Brève description du projet : </b> Nous avons décidé de représenter l'état du jeu via un vector de GameObject (un GameObject comprend un type et une position). Nous avons opté pour une architecture 'MVC', la vue n'intéragissant qu'avec son controller n'a donc pas d'accès direct au model. La  vue est également Observer du model, elle se met donc automatiquement à jour lorsque le model modifie ses données. Un fichier 'util.cpp' contient des méthodes statiques qui doivent être partagées dans plusieurs classes du model. Le role de chaque méthode est explicitement expliqué via son nom ou sa documentation. Une série de tests jugés pertinents sont implémentés via la librairie Catch2. Le jeu est construit à partir d'une TextView qui se charge d'instancier un controller et de lancer le jeu. Par soucis de pratique, la feature 'sauvegarder la partie' n'est disponible uniquement lorsqu'on gagne un niveau.</p>

<p><b>Les avertissements que contiennent le projet :</b> 
<ul>
    <li>
        Fonctions non utilisées (dans util.cpp). Ces fonctions sont utilisées mais pas dans ce fichier donc un avertissement est présent.
    </li>
</ul>
</p>

<p><b>Les bugs identifiés :</b> 
<ul>
    <li>
        Au niveau 4, le metal est affiché par desus Baba. <i>Piste d'amélioration : établir un ordre de priorité d'affichage par rapport aux éléments.</i>
    </li>
    <li>
        Quand isYou est d'un type concernant plusieurs éléments, on peut rencontrer des problèmes lorsque l'on croise un obstacle. <i>Piste d'amélioration : revoir la méthode.</i>
    </li>
</ul>
</p>

<br>
<h2>Release 3</h2>
<h3>Date : 26/05/2023</h3>
<p>Le projet graphique est disponible dans le répertoire <i>'remise_03/BabaIsYou'</i>.</p>
<p>le <code>working directory</code> de ce projet doit être (à partir de la racine 'BabaIsYou'): <code>/BabaIsYou/src</code></p>
<p><b>Brève description du projet : </b> Nous avons conçu une interface visuelle agréable et simple d'utilisation pour les utilisateurs avec toutes nos fonctionnalités via des raccourcis, des boutons et un menu d'application. Notre application n'est pas responsive (resize indisponible) et est conçue pour les appareils de DESKTOP uniquement. Les sprites ne sont chargés qu'une fois (en utilisant une seule spritesheet) par la vue afin d'éviter une surcharge progressive.</p>
<p><b>UPDATE : tous les points donnés dans votre feedback ont été patchés. De plus, tous les avertissement précédents ont également été supprimés.</b></p>

<p><b>Les avertissements que contiennent le projet :</b> 
<ul>
    <li>
        GuiView::displayUserSaves : Pass a context object as 3rd connect parameter.
    </li>
</ul>
</p>
<p>2 utilisations de new sont recensées dans le code sans delete (pour la création de vues) mais via cet attribut : setAttribute(Qt::WA_DeleteOnClose), le delete est implicitement appelé quand nécessaire</p>

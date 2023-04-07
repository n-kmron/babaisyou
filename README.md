<h1>BABA IS YOU by Cameron (58008) & Reda (58063)</h>
<h2>Release 1</h2>
<h3>Date : 17/02/2023</h3>
<p>Les documents relatifs à la première release du projet se trouvent dans le répertoire <i>'remise_01'</i> (Fichier UML et PDF)
PS : le fichier .mdj n'est pas documenté car un fichier pdf d'explications est demandé</p>

<br>
<h2>Release 2</h2>
<h3>Date : 21/04/2023</h3>
<p>Le projet console est disponible dans le répertoire <i>'remise_02/ProjectStructure'</i>. Le nom du projet n'est pas modifié suite à des difficultés rencontrées sur Qt creator</p>
<p><b>Brève description du projet : </b> Nous avons décidé de représenter l'état du jeu via un vector de GameObject (un GameObject comprend un type et une position). Nous avons opté pour une architecture 'MVC', la vue n'intéragissant qu'avec son controller n'a donc pas d'accès direct au model. La  vue est également Observer du model, elle se met donc automatiquement à jour lorsque le model modifie ses données. Un fichier 'util.cpp' contient des méthodes statiques qui doivent être partagées dans plusieurs classes du model. Le role de chaque méthode est explicitement expliqué via son nom ou sa documentation. Une série de tests jugés pertinents sont implémentés via la librairie Catch2. Le jeu est construit à partir d'une TextView qui se charge d'instancier un controller et de lancer le jeu.</p>

<p>Les avertissements que contiennent le projet : 
<ul>
    <li>Appel à une méthode virtuelle durant la construction d'un objet (TextView - displayTitle()) pour afficher le titre du jeu car c'est le seul moment disponible (après, le jeu sera lancé et il sera trop tard pour afficher le titre</li>
</ul>
</p>


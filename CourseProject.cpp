// CourseProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "CD.h"
#include "DVD.h"
#include "LinkedList.h"
#include "LinkedListDVD.h"
#include "Media.h"
#include <iostream>
using namespace std;

int main()
{
  
    CD cesar("album1", 30.50, "Cesar");
    cesar.setSong("cancion1", 2.30);
    cesar.setSong("cancion2", 3.05);
    cesar.setSong("cancion3", 3.15);
    CD emily("album2", 60.00, "Emily");
    emily.setSong("song1", 3.00);
    emily.setSong("song2", 5.00);
    CD daron("album3", 60.00, "Daron");
    daron.setSong("song1.3", 2.40);
    daron.setSong("song2.3", 4.00);

    LinkedList<CD> cdCollection;
    cdCollection.appendNode(cesar);
    cdCollection.appendNode(emily);
    cdCollection.appendNode(daron);
    cout << "added 3 cds" << endl;
    cdCollection.displayList();
    cdCollection.deleteNode(daron);
    cout << "removed 1 cd from the list" << endl;
    cdCollection.displayList();


    DVD pratt("Jurasic world", 2.15, 2018);
    pratt.setActors("chris pratt", "protagonist");
    pratt.setActors("girl", "love interest");
    DVD mcguire("Spiderman 1", 1.55, 2002);
    mcguire.setActors("bully mcguire", "spiderman");
    mcguire.setActors("willem dafoe", "green goblin");

    LinkedListDVD<DVD> DVDCollection;
    DVDCollection.appendNode(pratt);
    DVDCollection.appendNode(mcguire);
    cout << "added 2 movies" << endl;
    DVDCollection.displayList();
    DVDCollection.deleteNode(pratt);
    cout << "deleted the first movie from the list" << endl;
    DVDCollection.displayList();
}


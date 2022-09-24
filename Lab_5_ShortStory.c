// I made this February 8th, 2022
// My class is CSE 130 and my Lab number is no. 1 
// with the Section letter A
// This program is supposed to be a short interactive story
// where you can input things and get a slightly different story 
// each time you run the program

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char name[100];     // character string array to store inputed name
	char hobby[100];    // stores hobby input
	char tool[100];     // stores tool input
	char action[100];   // stores action input
	
	printf("You gain consciousness in some sort of dungeon cell.\n");
	printf("However, you can't seem to remember anything. Not even your name!\n");
	printf("What is your name?: ");
	scanf("%s", name);
	printf("Aha! you manage to remember your name. Your name is %s.\n", name);
	
	char *nameDesc[5] = {"stupid","cool","interesting","weird","unique"}; //gives a descriptor for your inputted name
	
	srand(time(0));
	
	int rNameDesc = rand() % 5;                                          //randomizes the descriptor
	
	printf("\"%s... what a %s name\" you think to yourself.\n\n", name, nameDesc[rNameDesc]);
    
	char *voiceDesc[5] = {"menacing","deep","intimidating","raspy","loud"}; //gives a descriptor for the mysterious voice
	
	srand(time(0));
	
	int rVoiceDesc = rand() % 5;                                           //randomizes the descriptor for the voice
	
	printf("You hear a %s voice ask you what your favorite", voiceDesc[rVoiceDesc]);
	printf("\nhobby was before being locked up");
	printf("\nWhat is your favorite hobby?: ");
	scanf("%s", hobby);
	printf("You seem to recall enjoying %s a lot. You say it out loud\n", hobby);
	
    char *hobbyDesc[5] = {"pathetic","special","strange","one of a kind","smart"}; //possible responses
	
	srand(time(0));
	
	int rHobbyDesc = rand() % 5; 												   //randomizes the response
	
	printf("\"%s you say?... ha ha you sure are %s if thats what you enjoyed to do\"", hobby, hobbyDesc[rHobbyDesc]);
	printf("\nYou hear the %s voice say.\n\n", voiceDesc[rVoiceDesc]);
	printf("It wasn't until now that it dawned upon you. You finally realize how dire\n");
	printf("the situation you're in is...");
	printf("\nDesperate to find something to aid you in you're escape from this mysterious place\n");
	printf("you dig into your pockets and you pull out an item from within them.");
	printf("\nWhat item do you pull out? (Just type item name, no \"a\" before hand): ");
	scanf("%s", tool);
	
	char *toolDesc[2] = {"?... \"Well thats not what I was expecting, but I can manage\" You say to yourself.","! \"Just what I needed!!\" You say to yourself."};     //the two possible reactions
	
	srand(time(0));
	
	int rToolDesc = rand() % 2;		 //randomizes the reaction to be printed
	
	printf("You pull out a %s%s", tool, toolDesc[rToolDesc]);
	
	printf("\n\nYou somehow manage to break out of your cell using the %s you pulled out.", tool);
	printf("\nYou walk out into the dark hallway outside your cell. Everything seems fine until...");
	
	char *monster[5] = {"goblin", "ghost", "orc", "demon", "skeleton"}; //possible monsters 
	
	srand(time(0));
	
	int rMonster = rand() % 5; //randomizes the monster you encounter
	
	printf("\nA wild %s appears!!!", monster[rMonster]);
	printf("\n\nYou panic to think of what to do and then suddenly...");
	printf("\nEnter an action (ex. fight): ");
	scanf("%s", action);
	printf("You decide to %s!", action);
	
	char *ending[3] = {"it finally overpowers you and brutally murders you... \nYour story sadly ends in tragedy, but maybe in another life you will succeed."
                      ,"you manage to overpower it and defeat it after a bloody battle! \nAfter your victory against your foe you manage to find your way out of the dungeon and you successfully escape!"
					  ,"you suddenly wake up on the ground of your apartment in a cold sweat... \nYou realize that the whole experience was part of a benadryl induced psychosis.\nYou get up, reflect upon the experience for a while, and go on with your day." }; //Possible endings
	
	srand(time(0));
	
	int rEnding = rand() % 3; //randomizes what ending will print out.
	
	printf("\nAfter a while of %sing with the %s %s ", action, monster[rMonster], ending[rEnding]);
	scanf("%d");
	return 0;
}

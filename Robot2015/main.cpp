/************************************************************
 * 															*
 * 	Auteur 	:	Thomas legrand								*	
 * 	Date	:	11 mai 2015									* 
 *	Fichier	:	princessBotik.cpp (Fichier source)			*
 *															*
 * 	Objectif:	Code principal du robot princess'botik		*
 * 															*	
 ************************************************************/

#include "TestAI.h"

const static int MATCH_TIME = 87;

void processAI(AbstractAI& ai) {
	Match* match = new Match(MATCH_TIME);

	// ai Init
	ai.init();

	printf("Fin init\n");

	// Wait for match to be ready
	match->waitStart();

	printf("fin wait match\n");

	// Init start
	ai.start(match);

	printf("fin start\n");

	// Match loop
	while(!match->isEnd()) {
		ai.run();
	}

	printf("fin du match\n");

	// End of match
	ai.end();
	delete match;
	exit(0);
}

int main(void) {
	TestAI ai;

	processAI(ai);
}
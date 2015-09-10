/************************************************************
 * 															*
 * 	Auteur 	:	Thomas legrand								*	
 * 	Date	:	11 mai 2015									* 
 *	Fichier	:	princessBotik.cpp (Fichier source)			*
 *															*
 * 	Objectif:	Code principal du robot princess'botik		*
 * 															*	
 ************************************************************/

#include "PrincessMatchAI.h"
#include "TestAI.h"

const static int MATCH_TIME = 87;

void processAI(AbstractAI& ai) {
	Match* match = new Match(MATCH_TIME);

	// ai Init
	ai.init();

	// Wait for match to be ready
	match->waitStart();

	// Init start
	ai.start(match);

	// Match loop
	while(!match->isEnd()) {
		ai.run();
	}

	// End of match
	ai.end();
	delete match;
	exit(0);
}

int main(void) {
	PrincessMatchAI ai;
	//TestAI ai;

	processAI(ai);
}
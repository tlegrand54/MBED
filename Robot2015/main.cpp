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

const static int MATCH_TIME = 87;

void processAI(AbstractAI& AI) {
	Match* match = new Match(MATCH_TIME);

	// AI Init
	AI.init();

	// Wait for match to be ready
	match->waitStart();

	// Init start
	AI.start(match);

	// Match loop
	while(!match->isEnd()) {
		AI.run();
	}

	// End of match
	AI.end();
	delete match;
	exit(0);
}

int main(void) {
	PrincessMatchAI AI;

	processAI(AI);
}
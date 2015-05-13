/************************************************************
 * 															*
 * 	Auteur 	:	Thomas legrand								*	
 * 	Date	:	11 mai 2015									* 
 *	Fichier	:	princessBotik.cpp (Fichier source)			*
 *															*
 * 	Objectif:	Code principal du robot princess'botik		*
 * 															*	
 ************************************************************/

#include "PrincessMatchIA.h"

const static int MATCH_TIME = 87;

void processIA(AbstractIA& ia) {
	Match* match = new Match(MATCH_TIME);

	// IA Init
	ia.init();

	// Wait for match to be ready
	match->waitStart();

	// Init start
	ia.start(match);

	// Match loop
	while(!match->isEnd()) {
		ia.run();
	}

	// End of match
	ia.end();
	delete match;
	exit(0);
}

int main(void) {
	PrincessMatchIA ia;

	processIA(ia);
}
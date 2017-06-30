#include "pawn.h"
#include "gameBitBoard.h"

Pawn::Pawn(int position120, Colour colour, bool firstMove) :
	Piece(position120, colour, PAWN, firstMove)
{
}
/*
 * move structure:
 * bits 0-6: 	the inital position.
 * bits 7-13: 	the destination position
 * bit 	14: 	determines if it is capturing an enemy piece
 *
 * Attacking moves are at the begining of the list and passive (non-capturing)
 * moves are at the end of the list. This is for future AI.
 */

list<uint32_t> Pawn::getPotentialMoves(GameBitBoard gameBitBoard)
{
	list<uint32_t> moves;

	int testDirection;

	int testTile;
	int testTile64;

	uint32_t moveToAdd = uint32_t(getPosition());

	getColour() == WHITE ? testDirection = direction : testDirection=direction*-1;

	testTile = getPosition()+testDirection;
	testTile64 = board120to64[testTile];

	if(isValidTile(testTile))
	{
		if(gameBitBoard.isTileFree(testTile64))
		{	
			moves.push_back(moveToAdd | (testTile<<7));
		}
		
	}
	
	if (isFirstMove())
	{
		testTile = testTile+testDirection;
		testTile64 = board120to64[testTile];

		if(isValidTile(testTile))
		{
			if(gameBitBoard.isTileFree(testTile64))
			{	
				moves.push_back(moveToAdd | (testTile<<7));
			}
			
		}
	}


	return moves;
}


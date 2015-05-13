#include "mbed.h"
#include "AX12Mbed.h"

#define PIN_TX p9
#define PIN_RX p10

Serial pc( USBTX , USBRX );

int baud = 115200;
int id = 6;
float angle = 200;


int main()
{
    pc.baud( baud );

    AX12 ax12( PIN_TX , PIN_RX , id , baud );
    
    printf( "\n" );
    printf( "Code pour test les ax12\n" );
    printf( "\n" );

    if( ax12.ping() )
    {
	printf( "\n" );
	printf( "Ping successful \n" );
	printf( "\n" );

	if( ax12.setCWLimit( 0 ) )
	{
	    printf( "\n" );
	    printf( "Change lower limit successful \n" );
	    printf( "\n" );
	} else {
	    printf( "\n" );
	    printf( "Change lower limit failed \n" );
	    printf( "\n" );
	}
	
	if( ax12.setCCWLimit( 0 ) )
	{
	    printf( "\n" );
	    printf( "Change upper limit successful \n" );
	    printf( "\n" );
	} else {
	    printf( "\n" );
	    printf( "Change upper limit failed \n" );
	    printf( "\n" );
	}

	if( ax12.setGoalSpeed( 0 ) )
	{
	    if( ax12.isMoving() )
	    {
	    	printf( "\n" );
		printf( "Moving \n" );
		printf( "\n" );
	    } else {
		printf( "\n" );
		printf( "No moving \n" );
		printf( "\n" );
	    }
	} else {
	    printf( "\n" );
	    printf( "Set speed failed \n" );
	    printf( "\n" );
	}	
    } else {
	printf( "\n" );
	printf( "Ping failed \n" );
	printf( "\n" );
    }
    
    
    return 0;
}

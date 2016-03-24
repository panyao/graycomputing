/**
 *  Copyright (C) 2009-2010, Ongaro Mattia <moongaro at gmail.com>
 *  All rights reserved.
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 */
 
/**
 *	That program uses polarSSL.
 *	Add to compiler by command line: -std=c99
 */
 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "md5.c"
#include "brute_force.c"

#define MAX_LENGTH 50

void hex_string_to_char ( const char * string, unsigned char * md5 );

int main ( int argc, char * argv [ ] )
{
    clock_t time_start;
    float time_end;
    long unsigned elements;
	unsigned range;
    char * base, start='a', end='z';
	unsigned char * hash;
    int num;
    char * target = {"a8f314562b3117c14d38c10d02e39c04"};


	
	if ( end <= start ) {
		fprintf ( stderr, "The second character must be bigger than the first: <starting character><terminating character>\nExample: az\n");
        return EXIT_FAILURE;
	}
	range = end - start;

	hash = ( unsigned char * ) calloc ( 17, sizeof ( char ) );
	hex_string_to_char ( target, hash );

	base = ( char * ) calloc ( MAX_LENGTH, sizeof ( char ) );
	strcpy ( base, "a" );

	printf ( "Hash: %s.\n"
			 "Starting String: %s.\n"
			 "Starting character: %c.\n"
			 "Terminating character: %c\n"
			 "Max length of the base string: %d.\n\n", target, base, start, end, MAX_LENGTH );
			 
	puts ( "Research ongoing..." );
	
	time_start = clock ( );
	num = brute_force ( base, strlen ( base ) - 1, hash, start, end );
	time_end = ( float ) ( clock ( ) - time_start );

    printf ( "String cracked in %f seconds.\n", time_end / CLOCKS_PER_SEC );
    elements = range;
    for ( int c = 1 ; c  < strlen ( base ) ; c++ ) {
		elements*=range;
    }
   
    printf ( "I searched between about %lu characters.\n", elements );
    printf ( "I searched %d string.\n", num );
    printf ( "String found: %s\n", base );
   
    return 0;
}

/*
 *		Put into the string called md5 a string made by hex values content inside the string called string
 */
void hex_string_to_char ( const char * string, unsigned char * md5 ) 
{
	unsigned char hex_to_char ( const char * hex );

	for ( short unsigned counter = 0 ; counter < 16 ; counter ++ ) {
		md5 [ counter ] = hex_to_char ( & string [ counter * 2 ] );
	}
}

/*
 *		Return the hex value represented by the string hex
 */
unsigned char hex_to_char ( const char * hex )
{
	unsigned char ret;
	if ( ( hex [ 0 ] - 0x61 ) >= 0 ) {
		ret = hex [ 0 ] - 0x57;
	}
	else if ( ( hex [ 0 ] - 0x41 ) >= 0 ) {
		ret = hex [ 0 ] - 0x37;
	}
	else {
		ret = hex [ 0 ] - 0x30;
	}

	ret = ret * 16;
	
	if ( ( hex [ 1 ] - 0x61 ) >= 0 ) {
		ret += hex [ 1 ] - 0x57;
	}
	else if ( ( hex [ 1 ] - 0x41 ) >= 0 ) {
		ret += hex [ 1 ] - 0x37;
	}
	else {
		ret += hex [ 1 ] - 0x30;
	}

	return ret;
}

/* End of main.c */
// Modification of the original program into the c language syntax

#include<stdio.h>
#include<conio.h>

/*
	Checks if page exists in frame
*/
int search(int key, int fr[]){
	int current_frame_size = sizeof(fr) / sizeof(fr[0]);
	
	// Loop through frame to determine if key exists
	int i = 0;
	for(i = 0; i < current_frame_size; i++) {
		if(key == fr[i]){
			return 1;
		}
	}
	return 0;
}

/*
	Function to find frame that will not be used
	in the most recent future
*/
int findFrame(int pg[], int fr[], int pn, int index) {
	// Store the index of pages which are going 
    // to be used recently in future
    int res = -1, farthest = index;
    int i = 0;
    int frame_size = sizeof(fr) / sizeof(fr[0]);
    for(i = 0; i < frame_size; i++) {
    	int j;
    	for(j = index; j < pn; j++) {
    		if(fr[i] == pg[j]) {
    			farthest = j;
    			res = i;
			}
			break;
		}
		
		// If a page is never referenced in future, 
        // return it.
        if(j == pn) {
        	return i;
		}
	}
	
	// If all of the frames were not in future, 
    // return any of them, we return 0. Otherwise 
    // we return res.
    if(res == -1) {
    	return 0;
	} else {
		return res;
	}
}

/*
	Actual algorithm to perform page replacement
*/
void optimalPage(int pg[], int pn, int fn) {
	
	// Create an array for given number of frames
	// Initialize all values in frame with -1
	int fr[fn]={-1,-1,-1,-1};
	int i = 0;
	
//	for(i = 0; i < 4; i++) {
//		fr[i] = -1;
//	}
	
	// Traverse through the page reference array
	int hits = 0;
	i = 0;
	for(i = 0; i < pn; i++) {
		
		// Checks if page exists in frame and adds a hit
		if(search(pg[i], fr)){
			hits++;
		} else {
			// Checks if there is space available in the frame
			// by finding if there is a -1 in the frame
			int index = 0;
			for(index = 0; index < fn; index++) {
				if(fr[index] == -1) {
					fr[index] = pg[i];
					break;
				}
			}
			
			if(index == (fn - 1)){
				// Find page to be replaced
				int j = findFrame(pg, fr, pn, i + 1); 
            	fr[j] = pg[i]; 
			}	
		}
	}
	
	printf("Hits: %d\n", hits);
	printf("Faults: %d\n", pn - hits);
}

// Main Driver Function
int main() {
	int pages[] ={1,2,5,4,1};
	int page_number = sizeof(pages) / sizeof(pages[0]);
	int frame_number = 4;
	optimalPage(pages, page_number, frame_number);
	return 0;
}

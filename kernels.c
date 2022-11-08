/********************************************************
 * Kernels to be optimized for the CS:APP Performance Lab
 ********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/* 
 * Please fill in the following team struct 
 */
team_t team = {
    "anti",              /* Team name */

    "Andreas Nicolaj Tietgen",     /* First member full name */
    "anti@itu.dk",  /* First member email address */

    "",                   /* Second member full name (leave blank if none) */
    ""                    /* Second member email addr (leave blank if none) */
};

/***************
 * ROTATE KERNEL
 ***************/

/******************************************************
 * Your different versions of the rotate kernel go here
 ******************************************************/

char rotate_another_one_descr[] = "rotate_another_one: here we try to change such that the outer loop is shortend";
void rotate_antoher_one(int dim, pixel *src, pixel *dst) 
{
    int i, j, si, ni, si_start;
    int bucket_size = 32; 
    int max = dim*dim;
    si_start = dim - 1; // Start at the end of first row
    si = si_start; // This is the index that is flipped 90 degrees
    ni = 0;

    // TODO: Get rid of the inner loop

    // TODO: Get rid of the unecessary variables

    for (i = 0; i < dim; i++) {

    	for (j = 0; j < dim; j+= bucket_size) {

	        dst[ni] = src[si];
            ni++; // Increment horizontally, left -> right
            si += dim; // Increment vertically, bottom -> top

	        dst[ni] = src[si];
            ni++;
            si += dim;
            
	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;
            
	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;
            
	        dst[ni] = src[si];
            ni++;
            si += dim;

	        dst[ni] = src[si];
            ni++;
            si += dim;
        }

        /*
        Now it is done with the inner loop. 
        Then we have to reset the si value such that we can continue.
        */

        // Here we try to do it in parts to gain pipeline parallelism
        si -= max;
        si--;
    }
}

/* 
 * basic_rotate: This is the first try of an implementation.
 * The idea here was to move the common computations out of the loop, use loop unrolling, and
 * memory aliasing.
 * Also i wanted to get rid of as many multiplication operations since they are "heavier" than
 * add or bit shifting.
 * 
 * Sadly this does not seem to provide any performance compared to the 
 * naive solution.
 */
char basic_rotate_descr[] = "basic_rotate: using basic optimizations to improve performance";
void basic_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;
    int bucket_size = 32; // TODO: IS this the correct bucket size that we use in the code?
    int max_index = dim * dim;
    int si_start = max_index;
    max_index--;
    int ni = 0;
    int si = si_start; // This is the index that is flipped 90 degrees

    for (i = 0; i < dim; i++) {

    	for (j = 0; j < dim; j += bucket_size) {

            // int strange_idx = (dim-1-j)*i+dim;
            // int normal_idx = i*j+dim;

            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;
            
	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;
            
	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            si -= dim;
            
	        dst[si] = src[ni];
            ni++;
            si -= dim;

	        dst[si] = src[ni];
            ni++;
            //si -= dim;
        }

        /*
        Now it is done with the inner loop. 
        Then we have to reset the si value such that we can continue.
        */
        si += si_start;
        si++;
    }
}
/* 
 * naive_rotate - The naive baseline version of rotate 
 */
char naive_rotate_descr[] = "naive_rotate: Naive baseline implementation";
void naive_rotate(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
    	for (j = 0; j < dim; j++)
	        dst[RIDX(dim-1-j, i, dim)] = src[RIDX(i, j, dim)];
}

/* 
 * rotate - Your current working version of rotate
 * IMPORTANT: This is the version you will be graded on
 */
char rotate_descr[] = "rotate: Current working version";
void rotate(int dim, pixel *src, pixel *dst) 
{
    rotate_antoher_one(dim, src, dst);
}

/*********************************************************************
 * register_rotate_functions - Register all of your different versions
 *     of the rotate kernel with the driver by calling the
 *     add_rotate_function() for each test function. When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_rotate_functions() 
{
    // add_rotate_function(&basic_rotate, basic_rotate_descr);
    add_rotate_function(&rotate_antoher_one, rotate_another_one_descr);
    add_rotate_function(&basic_rotate, basic_rotate_descr);
    add_rotate_function(&naive_rotate, naive_rotate_descr);   
    add_rotate_function(&rotate, rotate_descr);   
    /* ... Register additional test functions here */
}


/***************
 * SMOOTH KERNEL
 **************/

/***************************************************************
 * Various typedefs and helper functions for the smooth function
 * You may modify these any way you like.
 **************************************************************/

/* A struct used to compute averaged pixel value */
typedef struct {
    int red;
    int green;
    int blue;
    int num;
} pixel_sum;

/* Compute min and max of two integers, respectively */
static int min(int a, int b) { return (a < b ? a : b); }
static int max(int a, int b) { return (a > b ? a : b); }

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
static void initialize_pixel_sum(pixel_sum *sum) 
{
    sum->red = sum->green = sum->blue = 0;
    sum->num = 0;
    return;
}

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
static void accumulate_sum(pixel_sum *sum, pixel p) 
{
    sum->red += (int) p.red;
    sum->green += (int) p.green;
    sum->blue += (int) p.blue;
    sum->num++;
    return;
}

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
static void assign_sum_to_pixel(pixel *current_pixel, pixel_sum sum) 
{
    current_pixel->red = (unsigned short) (sum.red/sum.num);
    current_pixel->green = (unsigned short) (sum.green/sum.num);
    current_pixel->blue = (unsigned short) (sum.blue/sum.num);
    return;
}

/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
static pixel avg(int dim, int i, int j, pixel *src) 
{
    int ii, jj;
    pixel_sum sum;
    pixel current_pixel;

    initialize_pixel_sum(&sum);
    for(ii = max(i-1, 0); ii <= min(i+1, dim-1); ii++) 
	    for(jj = max(j-1, 0); jj <= min(j+1, dim-1); jj++) 
	        accumulate_sum(&sum, src[RIDX(ii, jj, dim)]);

    assign_sum_to_pixel(&current_pixel, sum);
    return current_pixel;
}

/******************************************************
 * Your different versions of the smooth kernel go here
 ******************************************************/

/*
 * naive_smooth - The naive baseline version of smooth 
 */
char naive_smooth_descr[] = "naive_smooth: Naive baseline implementation";
void naive_smooth(int dim, pixel *src, pixel *dst) 
{
    int i, j;

    for (i = 0; i < dim; i++)
	    for (j = 0; j < dim; j++)
	        dst[RIDX(i, j, dim)] = avg(dim, i, j, src);
}


/* 
 * avg - Returns averaged pixel value at (i,j) 
 */
// static pixel avg_basic(int dim, int i, int j, pixel *src) 
// {
//     int ii, red_acc = 0, green_acc = 0, blue_acc = 0, count = 0;
//     pixel current_pixel;

//     int max_row_idx = min(i+1, dim-1);
//     int max_col_idx = min(j+1, dim-1);
//     int min_row_idx = max(i-1, 0);
//     int min_col_idx = max(j-1, 0); 
//     // int row_diff = max_row_idx - min_row_idx;
//     int col_diff = max_col_idx - min_col_idx;

//     int idx = RIDX(min_row_idx, min_col_idx, dim);
//     pixel *p = src+idx;
//     if(col_diff == 2) {

//         for(ii = min_row_idx; ii <= max_row_idx; ii++) {

//             red_acc += p->red;
//             green_acc += p->green;
//             blue_acc += p->blue;
            
//             p++;
//             red_acc += p->red;
//             green_acc += p->green;
//             blue_acc += p->blue;

//             p++;
//             red_acc += p->red;
//             green_acc += p->green;
//             blue_acc += p->blue;

//             p += dim-2;
//             count+=3;
//         }
//     } else {

//         for(ii = min_row_idx; ii <= max_row_idx; ii++) {

//             red_acc += p->red;
//             green_acc += p->green;
//             blue_acc += p->blue;
            
//             p++;
//             red_acc += p->red;
//             green_acc += p->green;
//             blue_acc += p->blue;

//             p += dim-1;
//             count+=2;
//         }
//     }

//     current_pixel.red = (unsigned short) (red_acc/count);
//     current_pixel.green = (unsigned short) (green_acc/count);
//     current_pixel.blue = (unsigned short) (blue_acc/count);
//     return current_pixel;
// }

/*
* Calculates the average of the corners of the picture
*/
static void avg_corners_basic(int dim, int max, pixel *src, pixel *dst) {

    int red_acc = 0, green_acc = 0, blue_acc = 0;
    int max_row_index = dim - 1;
    int before_max = dim - 2;
    int count = 4;
    pixel current_pixel;

    // Corner 0,0
    
    int index = RIDX(0, 0, dim);
    pixel *p = src+index;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    p += dim-1;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    current_pixel.red = (unsigned short) (red_acc/count);
    current_pixel.green = (unsigned short) (green_acc/count);
    current_pixel.blue = (unsigned short) (blue_acc/count);

    dst[index] = current_pixel;

    // Corner dim-1, 0
    index = max_row_index;
    p = src+before_max;

    red_acc = 0;
    green_acc = 0;
    blue_acc = 0;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    p += dim-1;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    current_pixel.red = (unsigned short) (red_acc/count);
    current_pixel.green = (unsigned short) (green_acc/count);
    current_pixel.blue = (unsigned short) (blue_acc/count);

    dst[index] = current_pixel;
    index = (max-dim);
    p = src+(index-dim);

    red_acc = 0;
    green_acc = 0;
    blue_acc = 0;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    p += dim-1;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    current_pixel.red = (unsigned short) (red_acc/count);
    current_pixel.green = (unsigned short) (green_acc/count);
    current_pixel.blue = (unsigned short) (blue_acc/count);

    dst[index] = current_pixel;

    // Corner 0, dim-1
    index = (max-dim);
    p = src+(index-dim);

    red_acc = 0;
    green_acc = 0;
    blue_acc = 0;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    p += dim-1;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    current_pixel.red = (unsigned short) (red_acc/count);
    current_pixel.green = (unsigned short) (green_acc/count);
    current_pixel.blue = (unsigned short) (blue_acc/count);

    // Corner dim-1, dim-1
    index = max-1;
    p = src+((index-dim)-1);

    red_acc = 0;
    green_acc = 0;
    blue_acc = 0;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    p += dim-1;

    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;
            
    p++;
    red_acc += p->red;
    green_acc += p->green;
    blue_acc += p->blue;

    current_pixel.red = (unsigned short) (red_acc/count);
    current_pixel.green = (unsigned short) (green_acc/count);
    current_pixel.blue = (unsigned short) (blue_acc/count);

    dst[index] = current_pixel;
}

static void avg_sides_basic(int dim, int max, pixel *src, pixel *dst) {

    int max_row_index = dim - 1; 
    int left_red_acc = 0, left_green_acc = 0, left_blue_acc = 0;
    int right_red_acc = 0, right_green_acc = 0, right_blue_acc = 0;
    int top_red_acc = 0, top_green_acc = 0, top_blue_acc = 0;
    int bottom_red_acc = 0, bottom_green_acc = 0, bottom_blue_acc = 0;
    int count = 6;
    pixel current_left;
    pixel current_right;
    pixel current_top;
    pixel current_bottom;

    // Go through both sides
    int right_start_index = max_row_index + dim;
    int top_start_index = 1;
    int bottom_start_index = max - max_row_index;
    int left_start_index = dim+1;
    pixel *left = src+0;
    pixel *right = src+max_row_index;
    pixel *top = src+0;
    pixel *bottom = src+(max-dim);
    pixel *bottom_next = src+(max+dim);

    for(int i = 1; i < dim; i++) {

        left_red_acc = 0;
        left_green_acc = 0;
        left_blue_acc = 0;

        left_red_acc += left->red;
        left_green_acc += left->green;
        left_blue_acc += left->blue;
            
        left++;
        left_red_acc += left->red;
        left_green_acc += left->green;
        left_blue_acc += left->blue;

        left += max_row_index;

        left_red_acc += left->red;
        left_green_acc += left->green;
        left_blue_acc += left->blue;
            
        left++;
        left_red_acc += left->red;
        left_green_acc += left->green;
        left_blue_acc += left->blue;

        left += max_row_index;

        left_red_acc += left->red;
        left_green_acc += left->green;
        left_blue_acc += left->blue;
            
        left++;
        left_red_acc += left->red;
        left_green_acc += left->green;
        left_blue_acc += left->blue;
        
        current_left.red = (unsigned short) (left_red_acc/count);
        current_left.green = (unsigned short) (left_green_acc/count);
        current_left.blue = (unsigned short) (left_blue_acc/count);

        right_red_acc = 0;
        right_green_acc = 0;
        right_blue_acc = 0;

        right_red_acc += right->red;
        right_green_acc += right->green;
        right_blue_acc += right->blue;
            
        right++;
        right_red_acc += right->red;
        right_green_acc += right->green;
        right_blue_acc += right->blue;

        right += max_row_index;

        right_red_acc += right->red;
        right_green_acc += right->green;
        right_blue_acc += right->blue;
            
        right++;
        right_red_acc += right->red;
        right_green_acc += right->green;
        right_blue_acc += right->blue;

        right += max_row_index;

        right_red_acc += right->red;
        right_green_acc += right->green;
        right_blue_acc += right->blue;
            
        right++;
        right_red_acc += right->red;
        right_green_acc += right->green;
        right_blue_acc += right->blue;
        
        current_right.red = (unsigned short) (right_red_acc/count);
        current_right.green = (unsigned short) (right_green_acc/count);
        current_right.blue = (unsigned short) (right_blue_acc/count);

        // Store value
        dst[left_start_index] = current_left;
        dst[right_start_index] = current_right;
        left = src+left_start_index;
        right = src+(right_start_index+1);
        left_start_index += dim;
        right_start_index += dim;
    }

    // Go through both lengths
    for(int i = 1; i < dim; i++) {

        top_red_acc = 0;
        top_green_acc = 0;
        top_blue_acc = 0;

        top_red_acc += top->red;
        top_green_acc += top->green;
        top_blue_acc += top->blue;
            
        top++;
        top_red_acc += top->red;
        top_green_acc += top->green;
        top_blue_acc += top->blue;

        top++;
        top_red_acc += top->red;
        top_green_acc += top->green;
        top_blue_acc += top->blue;

        top += max_row_index;

        top_red_acc += top->red;
        top_green_acc += top->green;
        top_blue_acc += top->blue;
            
        top++;
        top_red_acc += top->red;
        top_green_acc += top->green;
        top_blue_acc += top->blue;

        top++;
        top_red_acc += top->red;
        top_green_acc += top->green;
        top_blue_acc += top->blue;
            
        current_top.red = (unsigned short) (top_red_acc/count);
        current_top.green = (unsigned short) (top_green_acc/count);
        current_top.blue = (unsigned short) (top_blue_acc/count);

        // Bottom        
        bottom_red_acc = 0;
        bottom_green_acc = 0;
        bottom_blue_acc = 0;

        bottom = bottom_next;
        bottom_next++;

        bottom_red_acc += bottom->red;
        bottom_green_acc += bottom->green;
        bottom_blue_acc += bottom->blue;
            
        bottom++;
        bottom_red_acc += bottom->red;
        bottom_green_acc += bottom->green;
        bottom_blue_acc += bottom->blue;

        bottom++;
        bottom_red_acc += bottom->red;
        bottom_green_acc += bottom->green;
        bottom_blue_acc += bottom->blue;

        bottom += max_row_index;

        bottom_red_acc += bottom->red;
        bottom_green_acc += bottom->green;
        bottom_blue_acc += bottom->blue;
            
        bottom++;
        bottom_red_acc += bottom->red;
        bottom_green_acc += bottom->green;
        bottom_blue_acc += bottom->blue;

        bottom++;
        bottom_red_acc += bottom->red;
        bottom_green_acc += bottom->green;
        bottom_blue_acc += bottom->blue;
            
        current_bottom.red = (unsigned short) (bottom_red_acc/count);
        current_bottom.green = (unsigned short) (bottom_green_acc/count);
        current_bottom.blue = (unsigned short) (bottom_blue_acc/count);

        // Store value
        dst[top_start_index] = current_top;
        dst[bottom_start_index] = current_bottom;
        top = src+(top_start_index + dim);
        bottom = src+(bottom_start_index-dim);
        top_start_index++;
        bottom_start_index++;
    }
}

static void avg_middle_basic(int dim, int max, pixel *src, pixel *dst) {

    int red_acc = 0, green_acc = 0, blue_acc = 0, count = 9;
    int index = 1;
    int range = dim-2;
    pixel *next = src+0;
    pixel *current;
    pixel current_pixel;

    for(int i = 0; i < range; i++) {

        for(int j = 0; i < range; j++) {

            current = next;
            next++;

            red_acc = 0;
            green_acc = 0;
            blue_acc = 0;

            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;
            
            current++;
            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;

            current++;
            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;
            
            current += dim-2;

            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;
            
            current++;
            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;

            current++;
            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;
            
            current += dim-2;

            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;
            
            current++;
            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;

            current++;
            red_acc += current->red;
            green_acc += current->green;
            blue_acc += current->blue;
            
            current_pixel.red = (unsigned short) (red_acc/count);
            current_pixel.green = (unsigned short) (green_acc/count);
            current_pixel.blue = (unsigned short) (blue_acc/count);

            dst[index] = current_pixel;
            index++;
        }

        index += 2;
        next++;
    }
}

/*
* basic smooth - ...
*/
char basic_smooth_descr[] = "basic_smooth: This is my first approach to a smooth implementation";
void basic_smooth(int dim, pixel *src, pixel *dst) {

    // int i, j;
    int max = dim * dim;

    // TODO: Go through corners first
    avg_corners_basic(dim, max, src, dst);

    // TODO: Go through sides
    avg_sides_basic(dim, max, src, dst);
    // TODO: Iterate through the middle
    avg_middle_basic(dim, max, src, dst);

}

/*
 * smooth - Your current working version of smooth. 
 * IMPORTANT: This is the version you will be graded on
 */
char smooth_descr[] = "smooth: Current working version";
void smooth(int dim, pixel *src, pixel *dst) 
{
    basic_smooth(dim, src, dst);
}


/********************************************************************* 
 * register_smooth_functions - Register all of your different versions
 *     of the smooth kernel with the driver by calling the
 *     add_smooth_function() for each test function.  When you run the
 *     driver program, it will test and report the performance of each
 *     registered test function.  
 *********************************************************************/

void register_smooth_functions() {
    add_smooth_function(&basic_smooth, basic_smooth_descr);
    add_smooth_function(&smooth, smooth_descr);
    add_smooth_function(&naive_smooth, naive_smooth_descr);
    /* ... Register additional test functions here */
}


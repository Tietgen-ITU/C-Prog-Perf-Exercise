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
static pixel avg_basic(int dim, int i, int j, pixel *src) 
{
    int ii, red_acc = 0, green_acc = 0, blue_acc = 0, count = 0;
    pixel current_pixel;

    int max_row_idx = min(i+1, dim-1);
    int max_col_idx = min(j+1, dim-1);
    int min_row_idx = max(i-1, 0);
    int min_col_idx = max(j-1, 0); 
    // int row_diff = max_row_idx - min_row_idx;
    int col_diff = max_col_idx - min_col_idx;

    int idx = RIDX(min_row_idx, min_col_idx, dim);
    pixel *p = src+idx;
    if(col_diff == 2) {

        for(ii = min_row_idx; ii <= max_row_idx; ii++) {

            red_acc += p->red;
            green_acc += p->green;
            blue_acc += p->blue;
            
            p++;
            red_acc += p->red;
            green_acc += p->green;
            blue_acc += p->blue;

            p++;
            red_acc += p->red;
            green_acc += p->green;
            blue_acc += p->blue;

            p += dim-2;
            count+=3;
        }
    } else {

        for(ii = min_row_idx; ii <= max_row_idx; ii++) {

            red_acc += p->red;
            green_acc += p->green;
            blue_acc += p->blue;
            
            p++;
            red_acc += p->red;
            green_acc += p->green;
            blue_acc += p->blue;

            p += dim-1;
            count+=2;
        }
    }

    current_pixel.red = (unsigned short) (red_acc/count);
    current_pixel.green = (unsigned short) (green_acc/count);
    current_pixel.blue = (unsigned short) (blue_acc/count);
    return current_pixel;
}

/*
* basic smooth - ...
*/
char basic_smooth_descr[] = "basic_smooth: This is my first approach to a smooth implementation";
void basic_smooth(int dim, pixel *src, pixel *dst) {

    int i, j;


    for (i = 0; i < dim; i++) {

	    for (j = 0; j < dim; j++) {

            dst[RIDX(i, j, dim)] = avg_basic(dim, i, j, src);
        }
    }
}

/* 
 * initialize_pixel_sum - Initializes all fields of sum to 0 
 */
// static void initialize_pixel_sum_basic(pixel_sum *sum) 
// {
//     sum->red = sum->green = sum->blue = 0;
//     sum->num = 0;
//     return;
// }

/* 
 * accumulate_sum - Accumulates field values of p in corresponding 
 * fields of sum 
 */
// static void accumulate_sum_basic(pixel_sum *sum, pixel p) 
// {
//     sum->red += (int) p.red;
//     sum->green += (int) p.green;
//     sum->blue += (int) p.blue;
//     sum->num++;
//     return;
// }

/* 
 * assign_sum_to_pixel - Computes averaged pixel value in current_pixel 
 */
// static void assign_sum_to_pixel_basic(pixel *current_pixel, pixel_sum sum) 
// {
//     current_pixel->red = (unsigned short) (sum.red/sum.num);
//     current_pixel->green = (unsigned short) (sum.green/sum.num);
//     current_pixel->blue = (unsigned short) (sum.blue/sum.num);
//     return;
// }

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


// Ryan M Jones
// CS350 w/Dr. Ely (original decimal_add.c supplied by Dr. Ely)
// Program #1
// Due: Monday, 4/8/2019

#include <stdio.h>

typedef
unsigned char
digit ;

// x is an array of digits

int input_decimal_integer(digit *x)
// return -1 if illegal, else put digits
// in the array x[] with x[0] containing
// the least significant digit and
// return the number of digits
{
  char v[100] ;
  int n ;
  scanf("%s",v) ;
  n = 0 ;
  while (v[n] != '\0') {
    if (v[n] < '0') return -1 ;
    if (v[n] > '9') return -1 ;
    n++ ;
  }

  int m = 0 ;
  n-- ;
  while (n >= 0) {
    x[m++] = v[n--] - '0' ;
    // makes ascii character an 8-bit value suitable for arithmetic
  }

  return m ;
}


int print_decimal_integer(digit *x, int n)
{
  int i ;
  for (i = n-1 ; i >= 0 ; i--) {
    printf("%c",x[i]+'0') ;
  }
}



int mult (digit *res,
	 digit *a, int m,
	 digit *b, int n)
{
  // 'a' and 'b' are my numbers to mult
  // 'm' and 'n' are the respective lengths of 'a' and 'b'

  /*
  int i,max ;

  // i is the length of the sum`1

  digit ad,bd,sum,carry ;

  if (m > n) { max = m ; } else { max = n ; }
  carry = 0 ;

  for (i = 0 ; i < max ; i++) {
    if (i >= m) { ad = 0 ; } else { ad = a[i] ; }
    if (i >= n) { bd = 0 ; } else { bd = b[i] ; }

    sum = ad + bd + carry ;
    // what is the biggest sum can be?

    if (sum >= 10) {
      sum = sum - 10 ;
      carry = 1 ;
    } else {
      carry = 0 ;
    }

    res[i] = sum ;
  }

  if (carry == 1) {
    res[i] = carry ;
    i++ ;
  }

  return i ;
  */

  // prepare arrays a and b for calculation w/ "- '0'" trick from class
  for(int i = 0; i < m; i++) {
    a[i] -= '0';
  }

  for(int i = 0; i < n; i++) {
    b[i] -= '0';
  }

  // note: the largest # from two digits of length 1 == 81 (9 * 9)
  for(int i = m - 1; i >= 0; i--) {
    for(int j = n - 1; j >= 0; j--) {
      res[i + j + 1] += (a[i] * b[j]);
      res[i + j]     += res[i + j + 1] / 10; // catch the "ones" place
      res[i + j + 1] =  res[i + j + 1] % 10; // catch the "tens" place
    }
  }

  // turn res array into the approrpiate value
  for(int i = 0; i < (n + m + 1); i++) {
    res[i] += '0';
  }

  // terminating character at end of array (little-endian, so this is one element past the most significant digit)
  res[n + m] = '\0';
  printf("Result = %s\n", res);

  // the add function returned the length of the sum, my code does the same. When multipling two digits of lengths n and m, the maximum length of the product is no more than (n + m)
  // for example, if n = 3 and m = 4, n * m will have a length of no more than 7
  return n + m;
}


int main()
{
  digit x[100], y[100], z[100] ;
  int xlen, ylen, zlen ;

  xlen = input_decimal_integer(x) ;
  printf("x = ") ; print_decimal_integer(x,xlen) ;  printf("\n") ;


  ylen = input_decimal_integer(y) ;
  printf("y = ") ; print_decimal_integer(y,ylen) ;  printf("\n") ;

  zlen = mult(z, x, xlen, y, ylen);

  printf("z = ") ; print_decimal_integer(z,zlen) ;  printf("\n") ;


}


#include <stdio.h>

typedef
unsigned char
digit ;

// x is an array of digits
int add (digit *res, digit *a, int m, digit *b, int n);

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
  // 'a' and 'b' are my numbers to add
  // 'm' and 'n' are the respective lengths of 'a' and 'b'

  int i,z,max,min ;

  // i is the length of the sum`1

  digit ad,bd,sum,carry ;
  
  if (m >= n) { max = m ; min = n ; } 
  else { 
    // If n is bigger than m, then swap objects. Largest number will always be a so that the remainder of the algorithm works correctly
    int swap = m;
    m = n;
    n = swap;

    digit * swapp = b;
    b = a;
    a = swapp;
    max = m ; 
    min = n;
  }

  

  digit initres[min][100];
  int lengths[100];
  carry = 0 ;
  
  for (z = 0; z < min; z++) {
    for (i = 0 ; i < max ; i++) {
      if (i >= m) { ad = 0 ; } else { ad = a[i] ; }
      //if (i >= n) { bd = 0 ; } else { bd = b[i] ; }
      bd = b[z];

      sum = (ad * bd) + carry ;
      // what is the biggest sum can be?

      if (sum >= 10) {
        /*
        sum = sum - 10 ;
        carry = 1 ;
        */
        carry = sum/10;
        sum = sum - (carry * 10);
      } else {
        carry = 0 ;
      }
      
      initres[z][i+z] = sum ;
      //res[i] = sum;
    }

    if (carry == 1) {
      initres[z][i+z] = carry ;
      //res[i] = carry;
      i++ ;
    }

    lengths[z] = i;

    if (z >= 1) {
      int zeros = z;
      int index = 0;
      while(zeros != 0){
        //printf("we're here once for index: %d\n", index);
        initres[z][index] = 0;
        index++;
        lengths[z]++;
        zeros--;
      }
    }

    
  }
  
  if(z >= 2) {
    // This conditional is for multiplying the longest number by two (or more) digits, the program needs additions to get the final result. 
    int resLength = 0;
    z--;
    int upto = 0;
    while (upto != z) {
      if(upto == 0) {
        resLength = add(res, initres[upto], lengths[upto], initres[upto+1], lengths[upto+1]);
      }
      else {
        resLength = add(res, res, resLength, initres[upto+1], lengths[upto+1]);
      }
      upto++;
    }
    return resLength;
  }
  else {
    // This conditional is for multiplying the longest number by one digit, the program doesn't need to do any additions. 
    for (int s = 0; s < i; s++) {
      res[s] = initres[0][s];
      
    }
    return i;
  }

}

int add (digit *res,
	 digit *a, int m,
	 digit *b, int n)
{
  // 'a' and 'b' are my numbers to add
  // 'm' and 'n' are the respective lengths of 'a' and 'b'

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
}

  
int main()
{
  digit x[100], y[100], z[100] ;
  int xlen, ylen, zlen ;

  xlen = input_decimal_integer(x) ;
  printf("x = ") ; print_decimal_integer(x,xlen) ;  printf("\n") ;


  ylen = input_decimal_integer(y) ;
  printf("y = ") ; print_decimal_integer(y,ylen) ;  printf("\n") ;
 
 /*
  int xx = 42;
  int carry = xx/10;
  xx = xx - ( carry * 10);
  printf("This int: %d\n", xx);

  x[0] = x[0] + 40;
  digit c = x[0]/10;
  x[0] = x[0] - (c * 10);
  printf("This x[0]: %c\n", x[0]+'0');
  printf("This c: %c\n", c+'0');



  return 1;
  */
 
  zlen = mult(z,   x,xlen,    y,ylen) ;
  
  //printf("z[0]: %c\n", z[0]+'0');
  //printf("z[1]: %c\n", z[1]+'0');
  printf("z = ") ; print_decimal_integer(z,zlen) ;  printf("\n") ;  
  return 1;

/*
  zlen = add(z,   x,xlen,    y,ylen) ;

  printf("z = ") ; print_decimal_integer(z,zlen) ;  printf("\n") ;  
*/


}

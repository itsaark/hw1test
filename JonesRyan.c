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
    printf("%c",x[i] + '0');
  }
}



int add (digit *res,
	 digit *a, int m,
	 digit *b, int n)
{
  // 'a' and 'b' are my numbers to add
  // 'm' and 'n' are the respective lengths of 'a' and 'b'

  int i,max ;

  int j;
  unsigned long temp;

  // i is the length of the sum`1

  digit ad,bd,sum,carry ;

  // if (m > n) { max = m; } else { max = n; }
  carry = 0 ;

  for (i = 0 ; i < (m + n - 1); i++) {
    //if (i >= m) { ad = 0 ; } else { ad = a[i] ; }
    //if (i >= n) { bd = 0 ; } else { bd = b[i] ; }
    for(j = 0; j < n; j++) {
      temp += (a[m] - '0') * (b[n] - '0');
    }

    res[i] = temp % 10 + '0';           // temp % 10 is the one's place
    temp = temp / 10;             // temp / 10 is the ten's place
    j = i + 1;

    while(temp > 0) {
      res[j] += temp % 10;
      temp = temp / 10;
      j++;
    }
  }


  return m + n;
}


int main()
{
  digit x[100], y[100], z[100] ;
  int xlen, ylen, zlen ;

  xlen = input_decimal_integer(x) ;
  printf("x = ") ; print_decimal_integer(x,xlen) ;  printf("\n") ;


  ylen = input_decimal_integer(y) ;
  printf("y = ") ; print_decimal_integer(y,ylen) ;  printf("\n") ;

  zlen = add(z,   x,xlen,    y,ylen) ;

  printf("z = ") ; print_decimal_integer(z,zlen) ;  printf("\n") ;


}

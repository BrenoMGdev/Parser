#include <stdio.h>

#define stacksize 5012

char stack[stacksize];
char word[stacksize];

int topstack, topword, q, t, p;

void pop() {
  --topstack;
}

void push(char value) {
  ++topstack;
  stack[topstack] = value;
}

void wordPush(char value) {
  ++topword;
  word[topword] = value;
}

void printTable(int step) {
  printf("%d\tq%d\tt%d", step, q, t);

  if(p == -1) {
    printf("\t-\t");
  } else {
    printf("\tp%d\t", p);
  }

  for(int i = topstack; i >= 0; --i) {
    printf("%c", stack[i]);
  }

  printf("\n");
}

int main(void) {
  topstack = topword = -1;

  int counter = 0;
  char token;

  printf("step\tqi\tti\tpi\tstack\n");

  q0:
    q = 0; t = 0; p = -1;

    printTable(counter);

    push('M'); //t0

    if(scanf("%c", &token) == EOF) {
      goto error;
    }

    goto q1;

  q1:
    counter += 1;
    q = 1;

    printTable(counter);

    if(stack[topstack] == 'M' && token == 'm') { //t1; p0
      t = 1; p = 0;

      pop();
      push('}');
      push(';');
      push(')');
      push('E');
      push('(');
      push('r');
      push(';');
      push('C');
      push('{');
      push(')');
      push('(');
      push('m');

      goto q1;
    } else if(stack[topstack] == 'C') {
      if(token == '0') { //t2; p1
        t = 2; p = 1;

        pop();
        push('0');

        goto q1;
      } else if(token == '1') { //t3; p2
        t = 3; p = 2;

        pop();
        push('1');

        goto q1;
      } else if(token == 'x') { //t4; p3
        t = 4; p = 3;

        pop();
        push('x');

        goto q1;
      } else if(token == 'y') { //t5; p4
        t = 5; p = 4;

        pop();
        push('y');

        goto q1;
      } else if(token == 'h') { //t6; p5
        t = 6; p = 5;

        pop();
        push('E');
        push('=');
        push('h');

        goto q1;
      } else if(token == 'i') { //t7; p6
        t = 7; p = 6;
        
        pop();
        push('E');
        push('=');
        push('i');

        goto q1;
      } else if(token == 'j') { //t8; p7
        t = 8; p = 7;
        
        pop();
        push('E');
        push('=');
        push('j');

        goto q1;
      } else if(token == 'k') { //t9; p8
        t = 9; p = 8;
        
        pop();
        push('E');
        push('=');
        push('k');

        goto q1;
      } else if(token == 'z') { //t10; p9
        t = 10; p = 9;
        
        pop();
        push('E');
        push('=');
        push('z');

        goto q1;
      } else if(token == '(') { //t11; p10
        t = 11; p = 10;
        
        pop();
        push(')');
        push('E');
        push('X');
        push('E');
        push('(');

        goto q1;
      } else if(token == 'w') { //t12; p11
        t = 12; p = 11;
        
        pop();
        push('}');
        push(';');
        push('C');
        push('{');
        push(')');
        push('E');
        push('(');
        push('w');

        goto q1;
      } else if(token == 'f') { //t13; p12
        t = 13; p = 12;
        
        pop();
        push('}');
        push(';');
        push('C');
        push('{');
        push(')');
        push('E');
        push('(');
        push('f');

        goto q1;
      } else if(token == 'o') { //t14; p13
        t = 14; p = 13;
        
        pop();
        push('}');
        push(';');
        push('C');
        push('{');
        push(')');
        push('E');
        push(';');
        push('E');
        push(';');
        push('E');
        push('(');
        push('o');

        goto q1;
      } else {
        goto error;
      }
    } else if(stack[topstack] == 'E') {
      if(token == '0') { //t15; p14
        t = 15; p = 14;
        
        pop();
        push('0');

        goto q1;
      } else if(token == '1') { //t16; p15
        t = 16; p = 15;
        
        pop();
        push('1');

        goto q1;
      } else if(token == 'x') { //t17; p16
        t = 17; p = 16;
        
        pop();
        push('x');

        goto q1;
      } else if(token == 'y') { //t18; p17
        t = 18; p = 17;
        
        pop();
        push('y');

        goto q1;
      } else if(token == '(') { //t19; p18
        t = 19; p = 18;
        
        pop();
        push(')');
        push('E');
        push('X');
        push('E');
        push('(');

        goto q1;
      } else {
        goto error;
      }
    } else if(stack[topstack] == 'X') {
      if(token == '+') { //t20; p19
        t = 20; p = 19;
        
        pop();
        push('+');

        goto q1;
      } else if(token == '-') { //t21; p20
        t = 21; p = 20;
        
        pop();
        push('-');

        goto q1;
      } else if(token == '*') { //t22; p21
        t = 22; p = 21;
        
        pop();
        push('*');

        goto q1;
      } else if(token == '/') { //t23; p22
        t = 23; p = 22;
        
        pop();
        push('/');

        goto q1;
      } else {
        goto error;
      }
    } else if(stack[topstack] == token && token == 'm') { //t24
      t = 24; p = -1;
      
      pop();
      wordPush('m');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }

      goto q1;
    } else if(stack[topstack] == token && token == 'r') { //t25
      t = 25; p = -1;
      
      pop();
      wordPush('r');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }

      goto q1;
    } else if(stack[topstack] == token && token == '(') { //t26
      t = 26; p = -1;
      
      pop();
      wordPush('(');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }

      goto q1;
    } else if(stack[topstack] == token && token == ')') { //t27
      t = 27; p = -1;
      
      pop();
      wordPush(')');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '{') { //t28
      t = 28; p = -1;
      
      pop();
      wordPush('{');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '}') { //t29
      t = 29; p = -1;
      
      pop();
      wordPush('}');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == ';') { //t30
      t = 30; p = -1;
      
      pop();
      wordPush(';');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '=') { //t31
      t = 31; p = -1;
      
      pop();
      wordPush('=');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'h') { //t32
      t = 32; p = -1;
      
      pop();
      wordPush('h');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'i') { //t33
      t = 33; p = -1;
      
      pop();
      wordPush('i');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'j') { //t34
      t = 34; p = -1;
      
      pop();
      wordPush('j');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'k') { //t35
      t = 35; p = -1;
      
      pop();
      wordPush('k');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'z') { //t36
      t = 36; p = -1;
      
      pop();
      wordPush('z');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'w') { //t37
      t = 37; p = -1;
      
      pop();
      wordPush('w');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'f') { //t38
      t = 38; p = -1;
      
      pop();
      wordPush('f');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'o') { //t39
      t = 39; p = -1;
      
      pop();
      wordPush('o');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '0') { //t40
      t = 40; p = -1;
      
      pop();
      wordPush('0');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '1') { //t41
      t = 41; p = -1;
      
      pop();
      wordPush('1');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'x') { //t42
      t = 42; p = -1;
      
      pop();
      wordPush('x');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == 'y') { //t43
      t = 43; p = -1;
      
      pop();
      wordPush('y');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '+') { //t44
      t = 44; p = -1;
      
      pop();
      wordPush('+');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '-') { //t45
      t = 45; p = -1;
      
      pop();
      wordPush('-');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '*') { //t46
      t = 46; p = -1;
      
      pop();
      wordPush('*');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else if(stack[topstack] == token && token == '/') { //t47
      t = 47; p = -1;
      
      pop();
      wordPush('/');

      if(scanf("%c", &token) == EOF) {
        goto end;
      }
      
      goto q1;
    } else {
      goto error;
    }

  error:
    printf("\nWord does not accept!\n");

    printf("\nWord until was accepted => ");

    for(int i = 0; i <= topword; ++i) {
      printf("%c", word[i]);
    }

    printf("\n");

    return(0);

  end:
    printf("\nEnd of word!\n");

    printf("\nWord => ");

    for(int i = 0; i <= topword; ++i) {
      printf("%c", word[i]);
    }

    printf("\n");

    return(0);
}

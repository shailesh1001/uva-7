/*
 * Author: Phillip LeBlanc
 * Problem:
 *
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define DEBUG 0
#define printd if (DEBUG) printf

enum ops { DAT, MOV, ADD, JMP, JMZ, SLT, CMP };
enum type_t { indirect, direct, immediate };

typedef struct {
  enum type_t type;
  int val;
} field_t;

typedef struct {
  enum ops opcode;
  field_t fieldA;
  field_t fieldB;
} instruction_t;

int norm(int r) {
  while (r < 0 || r > 7999) {
    if (r < 0)
      r+= 8000;
    else
      r-= 8000;
  }
  return r;
}
int nAdd(int x, int y) {
  x = norm(x);
  y = norm(y);
  int r = x+y;
  return norm(r);
}

int run_instruction(int loc, int war, instruction_t *memory) {
  int Aoffset, Boffset, Aadd,Badd;
  Aoffset = nAdd(loc, memory[loc].fieldA.val);
  if (memory[loc].fieldA.type == indirect)
    Aoffset = nAdd(memory[Aoffset].fieldB.val, Aoffset);
  Boffset = nAdd(loc, memory[loc].fieldB.val);
  if (memory[loc].fieldB.type == indirect)
    Boffset = nAdd(memory[Boffset].fieldB.val, Boffset);
  switch(memory[loc].opcode) {
    case DAT:
      printf("Program #%d is the winner.\n", (war^1)+1);
      return -1;
    case MOV:
      if (memory[loc].fieldA.type == immediate) {
        memory[Boffset].fieldB.val = memory[loc].fieldA.val;
        break;
      }
      memory[Boffset].opcode = memory[Aoffset].opcode;
      memory[Boffset].fieldA.type = memory[Aoffset].fieldA.type;
      memory[Boffset].fieldA.val = memory[Aoffset].fieldA.val;
      memory[Boffset].fieldB.type = memory[Aoffset].fieldB.type;
      memory[Boffset].fieldB.val = memory[Aoffset].fieldB.val;
      break;
    case ADD:
      if (memory[loc].fieldA.type == immediate) {
        memory[Boffset].fieldB.val = nAdd(memory[Boffset].fieldB.val, memory[loc].fieldA.val);
        break;
      }
      Aadd = nAdd(memory[Aoffset].fieldA.val, memory[Boffset].fieldA.val);
      Badd = nAdd(memory[Aoffset].fieldB.val, memory[Boffset].fieldB.val);
      memory[Boffset].fieldA.val = Aadd;
      memory[Boffset].fieldB.val = Badd;
      break;
    case JMP:
      return Aoffset;
    case JMZ:
      if (memory[Boffset].fieldB.val == 0)
        return Aoffset;
      break;
    case SLT:
      if (memory[loc].fieldA.type == immediate) {
        if ((norm(memory[loc].fieldA.val) < norm(memory[Boffset].fieldB.val)))
          return nAdd(loc,2);
        break;
      }
      if ((norm(memory[Aoffset].fieldB.val) < norm(memory[Boffset].fieldB.val)))
        return nAdd(loc,2);
      break;
    case CMP:
      if ((memory[Aoffset].opcode == memory[Boffset].opcode)&&
          (memory[Aoffset].fieldA.type == memory[Boffset].fieldA.type)&&
          (memory[Aoffset].fieldA.val  == memory[Boffset].fieldA.val)&&
          (memory[Aoffset].fieldB.type == memory[Boffset].fieldB.type)&&
          (memory[Aoffset].fieldB.val  == memory[Boffset].fieldB.val)) {
        return nAdd(loc,2);
      }
      break;
  }
  return nAdd(loc,1);
}

void run()
{
  instruction_t *memory = calloc(8000, sizeof(instruction_t));
  int num_lines, start_location,i,j,IPA,IPB;
  char instr[4];
  char Ac, Bc;
  int Ad, Bd;
  for (i=0;i<2;i++) {
    scanf("%d\n%d\n", &num_lines, &start_location);
    if (i == 0)
      IPA = start_location;
    else
      IPB = start_location;
    for (j=0;j<num_lines;j++) {
      scanf("%3s %c%d %c%d\n",instr,&Ac,&Ad,&Bc,&Bd);
      if (!strcmp(instr, "DAT"))
        memory[start_location].opcode = DAT;
      else if (!strcmp(instr, "MOV"))
        memory[start_location].opcode = MOV;
      else if (!strcmp(instr, "ADD"))
        memory[start_location].opcode = ADD;
      else if (!strcmp(instr, "JMP"))
        memory[start_location].opcode = JMP;
      else if (!strcmp(instr, "JMZ"))
        memory[start_location].opcode = JMZ;
      else if (!strcmp(instr, "SLT"))
        memory[start_location].opcode = SLT;
      else if (!strcmp(instr, "CMP"))
        memory[start_location].opcode = CMP;

      if (Ac == '#')
        memory[start_location].fieldA.type = immediate;
      else if (Ac == '$')
        memory[start_location].fieldA.type = direct;
      else if (Ac == '@')
        memory[start_location].fieldA.type = indirect;
      if (Bc == '#')
        memory[start_location].fieldB.type = immediate;
      else if (Bc == '$')
        memory[start_location].fieldB.type = direct;
      else if (Bc == '@')
        memory[start_location].fieldB.type = indirect;

      memory[start_location].fieldA.val = Ad;
      memory[start_location].fieldB.val = Bd;
      start_location = nAdd(start_location, 1);
    }
  }

  /*everything is loaded in*/
  for (i=0;i<16000;i++) {
    IPA = run_instruction(IPA, 0, memory);
    if (IPA == -1) {
      free(memory);
      return;
    }
    IPB = run_instruction(IPB, 1, memory);
    if (IPB == -1) {
      free(memory);
      return;
    }
  }
  printf("Programs are tied.\n");
  free(memory);
}

int main()
{
  int count,j;
  scanf("%d", &count);
  for (j=0;j<count;j++)
  {
    run();
  }
  return 0;
}


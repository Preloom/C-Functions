void sortAlgorithm(int values[], int part, int sort)
{
  
  int i; // lcv for outer loop going through array
  int j; // lcv for inner loop for sort
  int size; // size of array 

  // Executable Statements
  size = (part * 3);
  for(i = 0; i < size; i++)
  {
    for(j = 0; j < size; j++)
    {
      if(sort == 1) // descending sort 
      {
        if(values[j] < values[i]) // < = desc, > = asc
        {
          swapValues(&values[j], &values[i]);
        }
      }
      if(sort == 2) // asc sort
      {
        if(values[j] > values[i]) // < = desc, > = asc
        {
          swapValues(&values[j], &values[i]);
        }
      }
    }
  }

}

void swapValues(int* a, int* b)
{
  int temp; // temporarily stores one variable

  temp = *a;
  *a = *b;
  *b = temp;
}

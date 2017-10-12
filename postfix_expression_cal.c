//产生逆波兰表达式
string GenRPNotation(char[] intput)
{
    int n = input.length;
    if(n==0)
    {
      return "";
    }
    string result = ""

    Stack<Character>stack = new Stack(Character)();
    for(i = 0;i<n;i++)
    {
        if(input[i] == '/' || input[i] == '+'
      || input[i] == '*' || input[i] == '-')
      {
        if(result == "")
        {
          result = result + stack.pop();
        }
        char first = stack.pop();
        result = "(" + first+input[i]+result+")";
      }
      else
      {
         Stack.push(input[i]);
      }
    }
    return result;
}
// 计算逆波兰表达式
double calculateRPNotation(char[] input)
{
    int n = input.length;
    if(n == 0)
    {
      return 0.0;
    }
    boolean firstSign = true;

    Stack<Integer> Stack =  new Stack<Integer>();
    for(i=0;i<n;i++)
    {
      if(input[i] == '/' || input[i] == '+'
    || input[i] == '*' || input[i] == '-')
    {
        if(firstSign)
        {
          result = (double) stack.pop();
          firstSign = false;
        }

    int first = stack.pop();
    switch (input[i]) {
      case '/':
      result =  first/result;
      break;
      case '+':
      result = first+result;
      break;
      case '-':
      result = first - result;
      break;
      case '*':
      result = first*result;
      break;
      default:
      break;
    }
    }
   }
   else
   {
     stack.push(input[i] - '0');
   }
   return result;
}

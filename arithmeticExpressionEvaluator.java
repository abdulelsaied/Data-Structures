// Abdul El-Saied
// 9/29/2019
// CIS 27

import java.util.Stack;

public class arithmeticExpressionEvaluator {

    private static boolean isOp(char x) {
        return x == '*' || x == '/' || x == '-' || x == '+' || x == '^' || x == '(' || x == ')';
    }

    private static int pemdas(char x) { // add priority 
        switch (x) {
        case '+':
        case '-':
            return 0;

        case '*':
        case '/':
            return 1;

        case '^':
            return 2;
        }
        return -1;
    }

    private static boolean isVal(char x) {
        return (x >= 'a' && x <= 'z') || (x >= '0' && x <= '9'); // lowercase vars allowed
    }

    public static String convertToPostfix(String input) {
        Stack<Character> stack = new Stack<Character>();
        StringBuffer postfix = new StringBuffer(input.length());
        char c;

        for (int i = 0; i < input.length(); i++) {
            c = input.charAt(i);

            if (isVal(c) == true) {
                postfix.append(c);
            } else if (c == '(') {
                stack.push(c);
            }

            else if (c == ')') { // end of parentheses special case

                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix.append(stack.pop());
                }
                if (!stack.isEmpty() && stack.peek() != '(')
                    return null;
                else if(!stack.isEmpty())
                    stack.pop();
            }
            else if (isOp(c)) 
            {
                if (!stack.isEmpty() && pemdas(c) <= pemdas(stack.peek())) {
                    postfix.append(stack.pop());
                }
                stack.push(c);
            }
        }

        while (!stack.isEmpty()) {
            postfix.append(stack.pop());
        }
        return postfix.toString();
    }

    static int evaluatePostfix(String exp) 
    { 
        Stack<Integer> stack=new Stack<>(); 

        for(int i =0 ;i < exp.length() ;i++) 
        { 
            char c=exp.charAt(i); 
              
            if(Character.isDigit(c)) //operand pushed to stack
            stack.push(c - '0'); 
            
            else // pop top 2 elements 
            { 
                int top = stack.pop(); 
                int secondTop = stack.pop(); 
                  
                switch(c) 
                { 
                    case '+': 
                    stack.push(secondTop + top); 
                    break; 
                      
                    case '-': 
                    stack.push(secondTop - top); 
                    break; 
                    
                    case '*': 
                    stack.push(secondTop * top); 
                    break; 
                    
                    case '/': 
                    stack.push(secondTop / top); 
                    break; 
              } 
            } 
        } 
        return stack.pop();     
    }

    public static void main(String[] args) 
    {
        String infixInput = "5+(6/2)"; // sample input
        System.out.println(infixInput);
        System.out.println(convertToPostfix(infixInput));
        System.out.println(evaluatePostfix(convertToPostfix(infixInput)));
    }
}
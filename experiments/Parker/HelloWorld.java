/* This is a simple Java program. 
   FileName : "HelloWorld.java". */
   class HelloWorld 
   { 
       // Your program begins with a call to main(). 
       // Prints "Hello, World" to the terminal window. 
       public static void main(String args[]) 
       { 
           System.out.println("Hello, World");
           System.out.println("The sum is " + add(5,10));
       }
       public static int add(int a, int b)
       {
           return a + b;
       }
   } 
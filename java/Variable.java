public class Variable {

   static int a=10;
   int b;
   void func(){
       b=11;
       System.out.println(b);
   }

    public static void main(String[] args){
        int a=25;
        System.out.println(a);

        System.out.println(Variable.a);

        Variable var=new Variable();

        var.func();
        System.out.println(var.b);

        var.b=15;
        Variable.a=22;
        System.out.println(Variable.a);
        System.out.println(var.b);

    }
}

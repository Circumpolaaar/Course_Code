package b;

import a.*;

public class Inherit {
	public static void main(String[] args){
		Parent p = new Parent();
		//是Parent不同包的类
		//可以调用public
		//不可以调用private，void，protected

		//p.fm1();
		//p.fm2();
		//p.fm3();
		p.fm4();

		Child c = new Child();
		//是Child不同包的类
		//可以调用public
		//不可以调用private，void，protected

		//c.cm1();
		//c.cm2();
		//c.cm3();
		c.cm4();
		//c.fm1();
		//c.fm2();
		//c.fm3();
		c.fm4();

		GrandChild g = new GrandChild();
		//是GrandChild同一个包的类
		//可以调用public，默认，protected
		//不可以调用private
		
		//g.cm1();
		//g.cm2();
		//g.cm3();
		g.cm4();
		//g.fm1();
		//g.fm2();
		//g.fm3();
		g.fm4();
    }
}
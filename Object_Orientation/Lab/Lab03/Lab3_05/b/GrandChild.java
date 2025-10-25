package b;

import a.Child;

public class GrandChild extends Child {
	//是Child不同包的子类
	//可以调用public，protected
	//不可以调用private，void
	public static void main(String[] args){
		GrandChild g = new GrandChild();
		//g.cm1();
		//g.cm2();
		g.cm3();
		g.cm4();
		//g.fm1();
		//g.fm2();
		g.fm3();
		g.fm4();
    }
}

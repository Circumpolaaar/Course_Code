

public class ShapeSequence  {
    //属性    
    int index=0;//“栈指针”,指向空位
    private Shape[] shapes;
    int size;

    //构造方法
    ShapeSequence(int size){
        if(size<0) size=0;
        this.size=size;
        shapes = new Shape[size];
    }

    //其他方法
    //添加
    public void add(Shape shape){
        if(this.index<0||this.index>this.size-1){
            //什么也不干
            //指针无效/满了
            return;
        }
        else{
            //可以添加
            this.shapes[index]=shape;
            index++;
        }
    }
    //返回这个容器的字符串表达
    public String toString(){
        String str = "[";
        for(int i=0;i<index;i++){
            str+=this.shapes[i].getClass().getName().toLowerCase();
            str+=" ";
        }
        str+="]";

        return str;
    }
    //获取内部类实例
    public SequenceIterator iterator() {
        return new SequenceIterator(); 
    }

    //内部类
    private class SequenceIterator implements interFace<Shape>{
        int nowIndex;
        //默认构造方法
        SequenceIterator(){
            nowIndex=0;
        }
        
        //抽象方法
        
        //鉴定是否遍历完了
        public boolean isEnd(){
            if(nowIndex==index){
                return true;
            }
            else return false;
        }
        //返回迭代器指向的shape
        public Shape current(){
            if(this.isEnd()==true){
                return null;
            }
            else{
                return shapes[nowIndex];
            }
        }
        //移动
        public void moveNext(){
            if(this.isEnd()==true){
                //啥也不做
            }
            else{
                nowIndex++;
            }
        }
        //判断相等
        public boolean equals(Object o){
            
            if(o instanceof SequenceIterator){
                ShapeSequence.SequenceIterator that = (ShapeSequence.SequenceIterator) o;
               
                if(ShapeSequence.this== that.Outer()){
                    if(this.nowIndex==that.nowIndex){
                        return true;
                    }
                }
            }
            return false;
        }
        /* 
        public interFace<Shape> iterator(){
            return new SequenceIterator();
        }
        */
        //返回超类实例
        public ShapeSequence Outer(){
            return ShapeSequence.this;
        }
        
    }

}

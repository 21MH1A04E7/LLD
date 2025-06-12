class Singleton{
    constructor(){
        if(Singleton.instance){
            return Singleton.instance;
        }
        Singleton.instance=this;
    }

    static getInstance(){
        if(!Singleton.instance){
            Singleton.instance=new Singleton();
        }
        return Singleton.instance;
    }
}


const s1=Singleton.getInstance();
const s2=Singleton.getInstance();
console.log(s1===s2);
const os=require('os')
const curros={
    name: os.type(),
    user:os.userInfo(),
    release:os.release(),
    pri:function(){
        console.log(this)
    }
};
curros.pri()

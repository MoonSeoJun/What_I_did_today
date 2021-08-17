const { info } = require('node:console');
const nodemailer = require('nodemailer');

const email = {
    "host" : "",
    "port" : "",
    "secure" : false,
    "auth" : {
        "user" : "",
        "pass" : ""
    }
}

const send = async(Option) => {
    nodemailer.createTransport(email).sendMail(option, (error, info) => {
        if(error){
            console.log(error);
        }else{
            console.log(info);
            return info.response;
        }
    });
};

let email_data = {
    from: 'msj040130@naver.com',
    to : 'msj00130@email.com',
    subject : 'asdfasd',
    text: 'asdffsfsdfsdfsd'
}

send(email_data);
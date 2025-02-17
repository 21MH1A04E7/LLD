class User{
    constructor(name,email){
        this.name = name;
        this.email = email;
    }
}

// handle the user repository for saving to database and sending email
class UserRepository{
    saveToDatabase(user){
        // save to database
        console.log(`User saved to database: ${user.name} - ${user.email}`);
    }
}

//handle ther email servie
class EmailService{
    sendEmail(user){
        // send email
        console.log(`Email sent to: ${user.email}`);
    }
}

class UserManager{
    constructor(userRepository,emailService){
        this.userRepository = userRepository;
        this.emailService = emailService;
    }
    createUser(name,email){
        const user = new User(name, email);
        this.userRepository.saveToDatabase(user);//single responsibilty to save datbase
        this.emailService.sendEmail(user);//sendEmail
    }
}

// Example usage
const userRepository=new UserRepository();
const emailService=new EmailService();
const userManager1=new UserManager(userRepository,emailService)
userManager1.createUser('hariom','hkeleton@gmail.com')

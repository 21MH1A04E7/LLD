class Account {
  deposit(amount) {
    throw new Error("Must override deposit");
  }

  withdraw(amount) {
    throw new Error("Must override withdraw");
  }
}

class SavingAccount extends Account {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in Saving Account new balance: ${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdraw: ${amount} from Saving Account new balance: ${this.balance}`);
    } else {
      console.log("Insufficient funds in Saving Account");
    }
  }
}

class CurrentAccount extends Account {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in Current Account new balance: ${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdraw: ${amount} from Current Account new balance: ${this.balance}`);
    } else {
      console.log("Insufficient funds in Current Account");
    }
  }
}

class FixedTermAccount extends Account {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in Fixed Term Account new balance: ${this.balance}`);
  }

  withdraw(amount) {
    throw new Error("Withdrawal not allowed in Fixed Term Account");
  }
}

class BankClient {
  constructor(accounts) {
    this.accounts = accounts;
  }

  processTransactions() {
    for (const acc of this.accounts) {
      acc.deposit(1000);
      try {
        acc.withdraw(500);
      } catch (e) {
        console.log(`Exception: ${e.message}`);
      }
    }
  }
}

// === USAGE ===
const accounts = [
  new SavingAccount(),
  new CurrentAccount(),
  new FixedTermAccount()
];

const client = new BankClient(accounts);
client.processTransactions();

// 1. DepositOnlyAccount Interface
class DepositOnlyAccount {
  deposit(amount) {
    throw new Error("Method 'deposit()' must be implemented.");
  }
}

// 2. WithdrawableAccount Interface extends DepositOnlyAccount
class WithdrawableAccount extends DepositOnlyAccount {
  withdraw(amount) {
    throw new Error("Method 'withdraw()' must be implemented.");
  }
}

// SavingAccount
class SavingAccount extends WithdrawableAccount {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in Savings Account. New Balance: ${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdrawn: ${amount} from Savings Account. New Balance: ${this.balance}`);
    } else {
      console.log("Insufficient funds in Savings Account!");
    }
  }
}

// CurrentAccount
class CurrentAccount extends WithdrawableAccount {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in Current Account. New Balance: ${this.balance}`);
  }

  withdraw(amount) {
    if (this.balance >= amount) {
      this.balance -= amount;
      console.log(`Withdrawn: ${amount} from Current Account. New Balance: ${this.balance}`);
    } else {
      console.log("Insufficient funds in Current Account!");
    }
  }
}

// FixedTermAccount
class FixedTermAccount extends DepositOnlyAccount {
  constructor() {
    super();
    this.balance = 0;
  }

  deposit(amount) {
    this.balance += amount;
    console.log(`Deposited: ${amount} in Fixed Term Account. New Balance: ${this.balance}`);
  }
}

// BankClient
class BankClient {
  constructor(withdrawableAccounts, depositOnlyAccounts) {
    this.withdrawableAccounts = withdrawableAccounts;
    this.depositOnlyAccounts = depositOnlyAccounts;
  }

  processTransactions() {
    for (const acc of this.withdrawableAccounts) {
      acc.deposit(1000);
      acc.withdraw(500);
    }
    for (const acc of this.depositOnlyAccounts) {
      acc.deposit(5000);
    }
  }
}

// Main
const withdrawableAccounts = [
  new SavingAccount(),
  new CurrentAccount()
];

const depositOnlyAccounts = [
  new FixedTermAccount()
];

const client = new BankClient(withdrawableAccounts, depositOnlyAccounts);
client.processTransactions();

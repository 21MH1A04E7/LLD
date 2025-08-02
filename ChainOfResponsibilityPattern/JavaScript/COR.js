class MoneyHandler {
    constructor() {
        this.nextHandler = null;
    }

    setNextHandler(handler) {
        this.nextHandler = handler;
    }

    dispense(amount) {
        throw new Error("Method must be implemented by subclass");
    }
}

class ThousandHandler extends MoneyHandler {
    constructor(numNotes) {
        super();
        this.numNotes = numNotes;
    }

    dispense(amount) {
        let notesNeeded = Math.floor(amount / 1000);
        if (notesNeeded > this.numNotes) {
            notesNeeded = this.numNotes;
            this.numNotes = 0;
        } else {
            this.numNotes -= notesNeeded;
        }

        if (notesNeeded > 0)
            console.log(`Dispensing ${notesNeeded} x ₹1000 notes.`);

        let remainingAmount = amount - (notesNeeded * 1000);
        if (remainingAmount > 0) {
            if (this.nextHandler)
                this.nextHandler.dispense(remainingAmount);
            else
                console.log(`Remaining amount of ₹${remainingAmount} cannot be fulfilled (Insufficient fund in ATM)`);
        }
    }
}

class FiveHundredHandler extends MoneyHandler {
    constructor(numNotes) {
        super();
        this.numNotes = numNotes;
    }

    dispense(amount) {
        let notesNeeded = Math.floor(amount / 500);
        if (notesNeeded > this.numNotes) {
            notesNeeded = this.numNotes;
            this.numNotes = 0;
        } else {
            this.numNotes -= notesNeeded;
        }

        if (notesNeeded > 0)
            console.log(`Dispensing ${notesNeeded} x ₹500 notes.`);

        let remainingAmount = amount - (notesNeeded * 500);
        if (remainingAmount > 0) {
            if (this.nextHandler)
                this.nextHandler.dispense(remainingAmount);
            else
                console.log(`Remaining amount of ₹${remainingAmount} cannot be fulfilled (Insufficient fund in ATM)`);
        }
    }
}

class TwoHundredHandler extends MoneyHandler {
    constructor(numNotes) {
        super();
        this.numNotes = numNotes;
    }

    dispense(amount) {
        let notesNeeded = Math.floor(amount / 200);
        if (notesNeeded > this.numNotes) {
            notesNeeded = this.numNotes;
            this.numNotes = 0;
        } else {
            this.numNotes -= notesNeeded;
        }

        if (notesNeeded > 0)
            console.log(`Dispensing ${notesNeeded} x ₹200 notes.`);

        let remainingAmount = amount - (notesNeeded * 200);
        if (remainingAmount > 0) {
            if (this.nextHandler)
                this.nextHandler.dispense(remainingAmount);
            else
                console.log(`Remaining amount of ₹${remainingAmount} cannot be fulfilled (Insufficient fund in ATM)`);
        }
    }
}

class HundredHandler extends MoneyHandler {
    constructor(numNotes) {
        super();
        this.numNotes = numNotes;
    }

    dispense(amount) {
        let notesNeeded = Math.floor(amount / 100);
        if (notesNeeded > this.numNotes) {
            notesNeeded = this.numNotes;
            this.numNotes = 0;
        } else {
            this.numNotes -= notesNeeded;
        }

        if (notesNeeded > 0)
            console.log(`Dispensing ${notesNeeded} x ₹100 notes.`);

        let remainingAmount = amount - (notesNeeded * 100);
        if (remainingAmount > 0) {
            if (this.nextHandler)
                this.nextHandler.dispense(remainingAmount);
            else
                console.log(`Remaining amount of ₹${remainingAmount} cannot be fulfilled (Insufficient fund in ATM)`);
        }
    }
}

// Chain setup and test
const thousandHandler = new ThousandHandler(3);
const fiveHundredHandler = new FiveHundredHandler(5);
const twoHundredHandler = new TwoHundredHandler(10);
const hundredHandler = new HundredHandler(20);

thousandHandler.setNextHandler(fiveHundredHandler);
fiveHundredHandler.setNextHandler(twoHundredHandler);
twoHundredHandler.setNextHandler(hundredHandler);

const amountToWithdraw = 4000;
console.log(`\nDispensing amount: ₹${amountToWithdraw}`);
thousandHandler.dispense(amountToWithdraw);

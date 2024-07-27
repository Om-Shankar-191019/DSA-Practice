var employee1 = { firstName: "John", lastName: "Rodson" };
var employee2 = { firstName: "Jimmy", lastName: "Baily" };

function invite(greeting1, greeting2) {
  console.log(
    greeting1 + " " + this.firstName + " " + this.lastName + ", " + greeting2
  );
}

const inviteArrow = (greeting1, greeting2) => {
  console.log(
    greeting1 + " " + this.firstName + " " + this.lastName + ", " + greeting2
  );
};

inviteArrow.call(employee1, "HELLO", "Stonish");
invite.call(employee1, "HELLO", "Stonish");

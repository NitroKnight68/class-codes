let equalPressed = 0;
let evalInput = "";
let buttonInput = document.querySelectorAll(".button");
let input = document.getElementById("input");
let equal = document.getElementById("equal");
let allClear = document.getElementById("allClear");
let erase = document.getElementById("erase");

buttonInput.forEach((buttonClass) => {
	buttonClass.addEventListener("click", () => {
		if (equalPressed === 1) {
			equalPressed = 0;
		}
		input.value += (buttonClass.classList[2] + " ");
		evalInput += buttonClass.value;
	});
});

equal.addEventListener("click", () => {
	equalPressed = 1;
	input.value = "";
	let solution = eval(evalInput);
	if (!Number.isInteger(solution)) {
		solution = solution.toFixed(2);
    	}
	solutionText = solution.toString();
	for(let i = 0; i < solutionText.length; i++) {
		if(solutionText[i] == "1")
			input.value += "ONE ";
		else if(solutionText[i] == "2")
			input.value += "TWO ";
		else if(solutionText[i] == "3")
			input.value += "THREE ";
		else if(solutionText[i] == "4")
			input.value += "FOUR ";
		else if(solutionText[i] == "5")
			input.value += "FIVE ";
		else if(solutionText[i] == "6")
			input.value += "SIX ";
		else if(solutionText[i] == "7")
			input.value += "SEVEN ";
		else if(solutionText[i] == "8")
			input.value += "EIGHT ";
		else if(solutionText[i] == "9")
			input.value += "NINE ";
		else if(solutionText[i] == ".")
			input.value += "POINT ";
	}
});

allClear.addEventListener("click", () => {
	input.value = "";
	evalInput = "";
});

erase.addEventListener("click", () => {
	input.value = input.value.substr(0, input.value.length - 1);
});

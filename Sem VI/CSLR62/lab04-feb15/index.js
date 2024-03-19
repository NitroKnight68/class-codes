var counterContainer = document.querySelector(".count-display");
var resetButton = document.querySelector(".reset-button");
var visitCount = localStorage.getItem("page_view");

if (visitCount) {
	visitCount = Number(visitCount) + 1;
	localStorage.setItem("page_view", visitCount);
}
else {
	visitCount = 1;
	localStorage.setItem("page_view", 1);
}
counterContainer.innerHTML = visitCount;

resetButton.addEventListener("click", () => {
	visitCount = 1;
	localStorage.setItem("page_view", 1);
	counterContainer.innerHTML = visitCount;
});
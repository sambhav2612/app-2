const app = document.getElementById('root');

const container = document.createElement('div');
container.setAttribute('class', 'container');

app.appendChild(container);

var request = new XMLHttpRequest();

request.open('GET', 'api.json', true);

request.onload = function () {
    var data = JSON.parse(this.response);

    if (request.status >= 200 && request.status < 404) {
        data.forEach(contri => {
            const card = document.createElement('card');
            card.setAttribute('class', 'card');

            const name = document.createElement('h1');
            name.textContent = contri.name;

            const bio = document.createElement('p');
            bio.textContent = contri.bio;

            const quote = document.createElement('blockquote');
            quote.textContent = contri.quote;

            const button = document.createElement('button');
            button.textContent = contri.github_username;
            button.addEventListener("click", function() {
                window.open(contri.github_url);
            });

            container.appendChild(card);
            card.appendChild(name);
            card.appendChild(bio);
            card.appendChild(quote);
            card.appendChild(button);
        });
    } else {
        console.log("Bad Request");
    }
}

request.send();
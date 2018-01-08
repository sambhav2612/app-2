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

            const h1 = document.createElement('h1');
            h1.textContent = contri.name;

            const p = document.createElement('p');
            p.textContent = contri.description;

            const quote = document.createElement('blockquote');
            quote.textContent = contri.quote;

            const button = document.createElement('button');
            button.textContent = contri.github_username;
            button.addEventListener("click", function() {
                window.open(contri.github_url);
            });

            container.appendChild(card);
            card.appendChild(h1);
            card.appendChild(p);
            card.appendChild(quote);
            card.appendChild(button);
        });
    } else {
        console.log("Bad Request");
    }
}

request.send();
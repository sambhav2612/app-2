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
            const card = document.createElement('div');
            card.setAttribute('class', 'card');

            const card_body = document.createElement('div');
            card_body.setAttribute = ('class', 'card-body');

            const name = document.createElement('h1');
            name.setAttribute = ('class', 'card-title');
            name.textContent = contri.name;

            const bio = document.createElement('p');
            bio.setAttribute = ('class', 'card-text');
            bio.textContent = contri.bio;
            
            const anchor = document.createElement('a');
            anchor.textContent = contri.github_username;
            anchor.href = contri.github_url;
            anchor.target = "_blank";
            anchor.setAttribute = ('class', 'btn btn-dark');
            /*anchor.addEventListener("click", function() {
                window.open(contri.github_url);
            });*/

            container.appendChild(card);
            card.appendChild(card_body);
            card_body.appendChild(name);
            card_body.appendChild(bio);
            card_body.appendChild(anchor);
        });
    } else {
        console.log("Bad Request");
    }
}

request.send();
import requests

api_key = 'RGAPI-2f35c845-baf6-438c-99b7-84bb7cce4e4e'
request_headers = {
    "User-Agent": "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.159 Safari/537.36",
    "Accept-Language": "ko-KR,ko;q=0.9,en-US;q=0.8,en;q=0.7",
    "Accept-Charset": "application/x-www-form-urlencoded; charset=UTF-8",
    "Origin": "https://developer.riotgames.com",
    "X-Riot-Token": "RGAPI-2f35c845-baf6-438c-99b7-84bb7cce4e4e"
}
requests_url = 'https://kr.api.riotgames.com/lol/league/v4/challengerleagues/by-queue/RANKED_SOLO_5x5'

response = requests.get(url=requests_url, headers=request_headers)

print(len(response.json().get('entries')))
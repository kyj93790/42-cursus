# INCEPTION 🎲
1. [Docker: concept](https://velog.io/@kyj93790/Inception-Docker-tutorial)
2. [Docker: tutorial 1 - Playing with Busybox](https://velog.io/@kyj93790/Inception-Docker-tutorial-1)

## ✅ TO DO

### Mandatory
- [ ] Has to be done on **virtual machine**
- [ ] Have to use **docker compose**
- [ ] Docker image must have the **same name** as its corresponding service
- [ ] Each service has to run in a **dedicated container**
<br>

- [ ] container must be built either from the penultimate stable version of **Alpine** or **Debian**
- [ ] write my own **Dockerfiles**, one per service
- [ ] Dockerfiles must be called in my **docker-compose.yml** by my **Makfile**

#### 🛠️ Have to set up

- [ ] Docker container that contains NGINX with TLSv1.2 or TLSv1.3 only
- [ ] Docker container that contains WordPress + php-fpm (it must be installed and configured) only without nginx
- [ ] Docker container that contains MariaDB only without nginx
- [ ] A volume that contains your WordPress database
volume : 저장소
실제 compute의 공간을 container에 할당
container 자체는 실행을 할 때마다 초기 이미지 상태로 돌아간다.
container 자체에 저장하는 것은 의미가 없다.
DB와 같이 보존을 해야하는 정보가 있을 수 있다. 이런 것들을 우리가 실제로 할당한 메모리에 저장해 둔다. 그 volume을 container에 연결해두면 container가 실행될 때 그 메모리에 읽고 쓰는 작업이 가능해진다.
- [ ] A second volume that contains your WordPress website files
- [ ] A **docker-network** that establishes the connection between your containers
<br>


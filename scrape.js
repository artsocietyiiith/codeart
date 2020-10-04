const rp = require('request-promise');
const otcsv = require('objects-to-csv');
const cheerio = require('cheerio');

const getCompanies = async () => {
  const html = await rp(baseURL + searchURL);
  const businessMap = cheerio('a.business-name', html).map(async (i, e) => {
    const link = baseURL + e.attribs.href;
    const innerHtml = await rp(link);
    const emailAddress = cheerio('a.email-business', innerHtml).prop('href');
    const name = e.children[0].data;
    const phone = cheerio('p.phone', innerHtml).text();

    return {
      emailAddress,
      link,
      name,
      phone,
    }
  }).get();
  return Promise.all(businessMap);
};

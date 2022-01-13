# TODO
import asyncio
from pyppeteer import launch

def main:
    browser = await launch()
    context = await browser.createIncognitoBrowserContext()
    page    = await context.newPage()

    await page.goto('https://www.deepl.com/translator')

    # input into translate box
    textinput = await page.type("#lmt__textarea lmt__source_textarea lmt__textarea_base_style","着替")
    